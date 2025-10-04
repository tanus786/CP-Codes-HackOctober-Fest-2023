import random
import pygame as pg
import sys,time


pg.init()   #starting of the game 
screen_width  = 800   
screen_height = 800

# bg_img = pg.image.load('back1.jpg')
# bg_img = pg.transform.scale(bg_img,(800,800))

win = pg.display.set_mode((screen_width,screen_height))  #win is use for showing window of given width and height
paddle = pg.Rect((screen_width/2-60),770,120,15)  #paddle will draw at the bottom in the middle of width
clock = pg.time.Clock()

font = pg.font.Font('arial 1.ttf',36)
score_text = font.render('Score : 0',True,"#FFFF00",(0,0,0))
score_text_Rect = score_text.get_rect()
score_text_Rect.x = 10
score_text_Rect.y = 10

font2 = pg.font.Font('arial 1.ttf',64)
game_over_text = font2.render('GAME OVER',True,(255,0,0),(0,0,0))
game_over_text_rect = game_over_text.get_rect()
game_over_text_rect.center = (screen_width//2,screen_height//2)

font3 = pg.font.Font('arial 1.ttf',24)
choice_text = font3.render('Choose Mode ',True,"#97FFFF",(0,0,0))
choice_text_rect = choice_text.get_rect()
choice_text_rect.x = 575
choice_text_rect.y = 10


font4 = pg.font.Font('arial 1.ttf',18)
choice1_text = font4.render('1. Enter e for Easy ',True,"#97FFFF",(0,0,0))
choice1_text_rect = choice1_text.get_rect()
choice1_text_rect.x = 600
choice1_text_rect.y = 40


font5 = pg.font.Font('arial 1.ttf',18)
choice2_text = font5.render('2. Enter d for Difficult ',True,"#97FFFF",(0,0,0))
choice2_text_rect = choice2_text.get_rect()
choice2_text_rect.x = 600
choice2_text_rect.y = 60


font6 = pg.font.Font('arial 1.ttf',24)
reset_text = font6.render('Enter r for reset ',True,(219,112,147),(0,0,0))
reset_text_rect = reset_text.get_rect()
reset_text_rect.center = (screen_width//2,25)

font7 = pg.font.Font('arial 1.ttf',24)
exit_text = font7.render('Enter z for exit ',True,(219,112,147),(0,0,0))
exit_text_rect = exit_text.get_rect()
exit_text_rect.center = (screen_width//2,60)

font8 = pg.font.Font('arial 1.ttf',48)
welcome_text = font8.render('WELCOME ',True,"white",(0,0,0))
welcome_text_rect = welcome_text.get_rect()
welcome_text_rect.center = (screen_width//2,screen_height//2)

font9 = pg.font.Font('arial 1.ttf',24)
start_text = font9.render('Enter space to start the game ',True,(205,102,0),(0,0,0))
start_text_rect = start_text.get_rect()
start_text_rect.center = (screen_width//2,450)


run_game = True
start_game = False
paddle_speed = 10
max_ball_speed = 10
min_ball_speed = 5
ball_x_speed = 0
ball_y_speed = 0
old_time = time.time()   
target_fps = 60
score = 0
ball_x = paddle.x+60
ball_y = paddle.y-13
point = 0
z=0
clr = ["#54FF9F","#8A2BE2","#CD3333","#7FFF00","#800080","#ADFF2F"]
start=False

def score_updater(): 
    global score,score_text
    score+=1
    score_text = font.render(f'Score : {score}',True,"#FFFF00",(0,0,0))

def check_collision():
    global screen_width,paddle,ball_x,ball_y,ball_x_speed,ball_y_speed,start_game,point,z
    #for fixing paddle from going outside the screen 
    if paddle.x<0:
        paddle.x=0
    if paddle.x+120>screen_width:
        paddle.x = screen_width-120

    #for making ball from going outside the screen from left and right
    if ball_x-13<=0 or ball_x+13>=screen_width:
        ball_x_speed = -ball_x_speed
    if ball_y-13 <0:
        ball_y_speed = -ball_y_speed
    
    #when ball hit the paddle 
    if ball_y+13>=paddle.y-5 and start_game==True and ball_x>paddle.x and ball_x<paddle.x+120:
        ball_y-=15
        ball_y_speed=-ball_y_speed
        z+=1
        point = z%6
        score_updater()
    elif ball_y>paddle.y:
        game_over()

def game_over():
    global run_game
    run_game = False

def reset():
    global ball_x,ball_y,score,score_text
    ball_x = paddle.x+60
    ball_y = paddle.y-13
    score =0
    score_text = font.render(f'Score : {score}',True,"#FFFF00",(0,0,0))



while True :
    new_time = time.time()  #time after the frame change
    dt = new_time-old_time  #time between frame change
    old_time = new_time

    for event in pg.event.get():
        if event.type == pg.QUIT or (event.type==pg.KEYDOWN and event.key == pg.K_z):
            pg.quit()
            sys.exit()
        

        if event.type==pg.KEYDOWN:
            if event.key==pg.K_e:
                target_fps = 60
            elif event.key == pg.K_d:
                target_fps = 90
            
            if event.key==pg.K_r:
                run_game = True
                start_game = False
                reset()
                
       
            if event.key==pg.K_SPACE:
                start_game = True
                ball_y-=10
                sign = random.randint(0,1)
                ball_y_speed = -random.randint(min_ball_speed,max_ball_speed)
                ball_x_speed = random.randint(min_ball_speed,max_ball_speed)
                if sign ==0:
                    ball_x_speed =-ball_x_speed

    if run_game==True:
        check_collision()
        key = pg.key.get_pressed()    #the keys which are pressed stored in key variable
        if key[pg.K_RIGHT]:
            paddle.x+=paddle_speed*dt*target_fps
            if start_game==False:
                ball_x=paddle.x+60
        elif key[pg.K_LEFT]:
            paddle.x-=paddle_speed*dt*target_fps
            if start_game==False:
                ball_x=paddle.x+60

        win.fill("black")  #insted of clearing background we fill color
        # win.blit(bg_img,(0,0))  
        pg.draw.rect(win,"white",paddle)   #padlle will be drawn at the specified positions
        if start_game == False:
            win.blit(welcome_text,welcome_text_rect)
            win.blit(start_text,start_text_rect)
            pg.display.update()
            pg.draw.circle(win,"white",(ball_x,ball_y),13)
        else:
            ball_x+=ball_x_speed*dt*target_fps
            ball_y+=ball_y_speed*dt*target_fps
            pg.draw.circle(win,clr[point] ,(ball_x,ball_y),13)

    else:
        win.blit(game_over_text,game_over_text_rect)
        
    win.blit(score_text,score_text_Rect)
    win.blit(choice_text,choice_text_rect)
    win.blit(choice1_text,choice1_text_rect)
    win.blit(choice2_text,choice2_text_rect)
    win.blit(reset_text,reset_text_rect)
    win.blit(exit_text,exit_text_rect)
    pg.display.update()
    clock.tick(60)
