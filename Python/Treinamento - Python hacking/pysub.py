import threading
import argparse as ap
from colorama import init
import queue
from socket import gethostbyname
from termcolor import colored

def load_search(subfile, domain):
    subqueue = queue.Queue()

    [subqueue.put(sub.strip() + '.' + domain) for sub in subfile.readlines()]
    return subqueue

def subdomain_search():
    while not workqueue.empty():
        addr = workqueue.get()

        try:
            hostip = gethostbyname(addr)
            print(colored('[+]', 'green') + f'Subdomínio encontrado!! {addr} com endereço IP {hostip}.')
            domainsfound.append((addr,hostip))
        except:
            print(colored('[-]', 'red') + f'Subdomínio {addr} não encontrado.')

        workqueue.task_done()




if __name__ == '__main__':

    parser = ap.ArgumentParser(description='Enumeração de subdomínios')

    parser.add_argument('-d', '--domain', help='O domínio a ser testado.', required=True)
    parser.add_argument('-w', '--wordlist', help='Um arquivo contendo subdomínios a serem testados.', required=True, type=ap.FileType(mode='r'))
    parser.add_argument('-t', '--threads', help='O número de threads a serem usadas. O padrão é 1.', default=1, type=int)
    parser.add_argument('-o', '--output', help='Arquivo para salvar os resultados.', type=ap.FileType(mode='w'))

    args = parser.parse_args()

    init()

    workqueue = load_search(args.wordlist, args.domain)
    domainsfound = []

    for _ in range(args.threads):
        threading.Thread(target=subdomain_search).start()

    workqueue.join()

    print('\n######################################################################\n')
    print(f'Encontrados um total de {len(domainsfound)} subdomínios.')

    if args.output:
        for item in domainsfound:
            args.output.write(f'{item[0]},{item[1]}\n')
        print(f'Lista de subdomínios salva em {args.output.name}')

    else:
        for item in domainsfound:
            print(f'{item[0]},{item[1]}')









