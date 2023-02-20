def solve(stack, n):
    premium = 0
    memo = []   
    for i in range(1, n+1):
        line = i*[0]
        memo.append(line) 
    
    memo[0][0] = stack[0][0]

    for i in range(n):
        for j in range(len(stack[i])):
            if (j == 0):
                memo[i][j] = memo[i-1][j] + stack[i][j]

            elif (j == i): 
                memo[i][j] = memo[i-1][j-1] + stack[i][j]

            else: 
                memo[i][j] = stack[i-1][j-1] + memo[i-1][j] + stack[i][j]
                

            premium = max(premium, memo[i][j])

    return premium + 1 if (premium != 0) else premium 


if __name__ == "__main__":
    
    while (1):
        n = int(input())
        if (n == 0): break 
        
        stack = [] 
        for i in range(n):
            line = [int(i) for i in input().split()]
            stack.append(line)
        
        print(solve(stack, n))