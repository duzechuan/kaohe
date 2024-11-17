import socket
def main():
    # 服务器的地址和端口
    server_address = ('127.0.0.1', 12345)
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)# 创建 TCP/IP 套接字
    try:
        client_socket.connect(server_address)
        a = float(input("请输入第一条直角边的长度: "))
        b = float(input("请输入第二条直角边的长度: "))
        # 发送数据到服务器
        message = f"{a} {b}"
        client_socket.sendall(message.encode('utf-8'))
        response = client_socket.recv(1024)        # 接收来自服务器的响应
        print(f"斜边的长度是: {response.decode('utf-8')}")

    except Exception as e:
        print(f"发生错误: {e}")

    finally:
        client_socket.close()# 关闭套接字

if __name__ == "__main__":
    main()
