class UrlExtrator:
    def __init__(self,url):
        if self.UrlValidation(url):
            self.url = url
        else:
            raise LookupError("Url invalida !!!")
    
    @staticmethod
    def UrlValidation(url):
        if url:
            return True
        else:
            return False


    def ExtractArgs(self):

        buscaMoedaOrigem ="moedaorigem=" 
        buscaMoedaDestino = "moedadestino="


        indexInicoMoedaOrigem = self.FindIndexInicial(buscaMoedaOrigem)
        indexFinalMoedaOrigem = self.url.find("&")

        
        moedaOrigem = self.url[indexInicoMoedaOrigem:indexFinalMoedaOrigem]
        if moedaOrigem == "moedadestino":
            self.TrocaMoedaOrigem()
            indexInicoMoedaOrigem = self.FindIndexInicial(buscaMoedaOrigem)
            indexFinalMoedaOrigem = self.url.find("&")
            moedaOrigem = self.url[indexInicoMoedaOrigem:indexFinalMoedaOrigem]
        
        indexInicioMoedaDestino = self.FindIndexInicial(buscaMoedaDestino)
        moedaDestino = self.url[indexInicioMoedaDestino:]

        return moedaOrigem,moedaDestino

    def FindIndexInicial(self,moedaBuscada):
        return self.url.find(moedaBuscada) + len(moedaBuscada)


    def TrocaMoedaOrigem(self):
        self.url = self.url.replace("moedadestino","real",1)
        print(self.url)

