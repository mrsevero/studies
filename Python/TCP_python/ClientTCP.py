import socket #importa modulo socket

TCP_IP = '192.168.0.10' # endereço IP do servidor 
TCP_PORTA = 41781      # porta disponibilizada pelo servidor
TAMANHO_BUFFER = 1024

# Criação de socket TCP do cliente
cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor em IP e porta especifica 
cliente.connect((TCP_IP, TCP_PORTA))


while 1:
        MENSAGEM  = input("Digite sua mensagem para o servidor: ")
        # envia mensagem para servidor
        cliente.send(MENSAGEM.encode('UTF-8'))
        if MENSAGEM.upper() == "QUIT":
                break
        # recebe dados do servidor
        data, addr = cliente.recvfrom(1024)
        print ("received data:", data)
        if("QUIT" in str(data.upper())):
                print ("FLW")
                break


# fecha conexão com servidor
cliente.close()
