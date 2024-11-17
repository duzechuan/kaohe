def xor_encrypt_decrypt(input_string, key):# 加密解密函数
    return ''.join(chr(ord(c) ^ key) for c in input_string)# 异或

filename = r'3\input.txt'
# 读取文件内容
with open(filename, 'r', encoding='utf-8') as file:# 打开文件
    content = file.read()

key = 7831  # 密钥，替换为你的学号
encrypted_content = xor_encrypt_decrypt(content, key)# 加密
# 写入加密后的内容到文件
with open('3\encrypted.txt', 'w', encoding='utf-8') as file:
    file.write(encrypted_content)
