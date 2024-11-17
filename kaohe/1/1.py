import numpy as np

def main():
    try:
        # 输入矩阵的维度
        n = int(input())
        
        # 输入矩阵
        matrix = []
        print()
        
        for i in range(n):
            row = list(map(float, input().strip().split()))  # 去掉空格和换行符，并转换为浮点数
            if len(row) != n:
                print("输入错误：每行元素数量必须等于矩阵的维度。")# 若输入错误，则返回
                return
            matrix.append(row)  # 加入矩阵
        
        matrix = np.array(matrix)  # 转换为 numpy 数组
        
        # 计算逆矩阵
        inverse_matrix = np.linalg.inv(matrix)  # 计算逆矩阵
        print("逆矩阵为：")
        print(inverse_matrix)
        
    except ValueError:
        print("输入错误：无效的数字格式。")
    except np.linalg.LinAlgError:
        print("矩阵不可逆")
    except Exception as e:
        print(f"发生错误：{e}")

if __name__ == "__main__":
    main()
