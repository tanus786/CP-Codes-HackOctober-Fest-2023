lass Solution:
    def lemonadeChange(self, N, bills):
        # Code here
        if bills[0] != 5:
            return False
        five = 0
        ten = 0
        for i in bills:
            if i == 5:
                five += 1
            elif i == 10:
                if five == 0:
                    return False
                else:
                    five -= 1
                    ten += 1
            else:
                if five > 0 and ten > 0:
                    five -= 1
                    ten -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True
        