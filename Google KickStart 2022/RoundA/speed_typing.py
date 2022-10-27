from collections import Counter
def check_forward(I, P):
    bucket, passed = [], 0
    I_cnt = sorted(Counter(I).items(), key=lambda x: [x[0].isupper(), x[0]])
    P_cnt = sorted(Counter(P).items(), key=lambda x: [x[0].isupper(), x[0]])
    for i in range(len(P_cnt)):
        try:
            if P_cnt[i][0] != I_cnt[i-passed][0]:
                for j in range(P_cnt[i][1]):
                    bucket.append(P_cnt[i][0])
                passed += 1
            elif P_cnt[i][1] < I_cnt[i-passed][1]:
                print(f"Case #{str(t)}: IMPOSSIBLE")
                break
            elif P_cnt[i][1] > I_cnt[i-passed][1]:
                for j in range(P_cnt[i][1] - I_cnt[i-passed][1]):
                    bucket.append(P_cnt[i][0])
        except:
            for j in range(P_cnt[i][1]):
                bucket.append(P_cnt[i][0])
    return bucket

def main():
    T = int(input())
    for t in range(1, T + 1):
        I = list(input())
        P = list(input())
        if set(I) != set(P):
            print(f"Case #{str(t)}: IMPOSSIBLE")
        else:
            print(f"Case #{str(t)}: {str(len(check_forward(I, P)))}")

if __name__=="__main__":
    main()


def check_forward(I, P):
    bucket, passed = [], 0
    I = sorted(I, key=lambda x: [x.isupper(), x])
    P = sorted(P, key=lambda x: [x.isupper(), x])
    for i in range(len(P)):
        try:
            if P[i] != I[i-passed]:
                bucket.append(P[i])
                passed += 1
        except:
            bucket.append(P[i])
    return bucket

def main():
    T = int(input())
    for t in range(1, T + 1):
        I = list(input())
        P = list(input())
        if set(I) != set(P):
            print(f"Case #{str(t)}: IMPOSSIBLE")
        # elif len(I) > len(P):
        #     for l in P:
        #         I.pop(l)
        #     print(f"Case #{str(t)}: {str(len(I))}")
        else:
            print(f"Case #{str(t)}: {str(len(check_forward(I, P)))}")

if __name__=="__main__":
    main()