import numpy as np

def main():
    # 输入矩阵的维度
    n = int(input())
    
    # 输入矩阵
    matrix = []
    print()
    for i in range(n):
        row = list(map(float, input().strip().split()))# 去掉空格和换行符，并转换为浮点数
        if len(row) != n:
            print("err")
            return
        matrix.append(row)# 加入矩阵
    matrix = np.array(matrix)# 转换为 numpy 
    # 计算逆矩阵
    try:
        inverse_matrix = np.linalg.inv(matrix)# 计算逆矩阵
        print(inverse_matrix)
    except np.linalg.LinAlgError:
        print("矩阵不可逆")

if __name__ == "__main__":
    main()
