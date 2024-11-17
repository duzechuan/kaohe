def xor_encrypt_decrypt(input_string, key):
    return ''.join(chr(ord(c) ^ key) for c in input_string)

filename = r'3\neuracecar_encrypted.txt'# 读取加密文件内容
with open(filename, 'r', encoding='utf-8') as file:
    encrypted_content = file.read()

key = 123456  # 解密密钥

# 解密
decrypted_content = xor_encrypt_decrypt(encrypted_content, key)

# 写入解密后的内容到文件
with open(r'3\neuracecar_decrypted.txt', 'w', encoding='utf-8') as file:
    file.write(decrypted_content)
