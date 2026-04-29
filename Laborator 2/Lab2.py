class Invatator:
    def __init__(self):
        self.nume = ""
        self.scoala = ""
        self.clasa = ""
        self.norma = 0
        self.vechime = 0.0
    def set_nume(self, nume):
        self.nume = nume
    def set_scoala(self, scoala):
        self.scoala = scoala
    def set_clasa(self, clasa):
        self.clasa = clasa

    def set_norma_didactica(self, norma):
        self.norma = norma
    def set_vechime(self, vechime):
        self.vechime = vechime
    def afiseaza(self):
        print("Invatator:", self.nume)
        print("Scoala:", self.scoala)
        print("Clasa:", self.clasa)
        print("Norma:", self.norma)
        print("Vechime:", self.vechime)
# utilizare
inv = Invatator()
inv.set_nume("Cimpoi Naomi")
inv.set_scoala("Scoala Gimnaziala Dornesti")
inv.set_clasa("a III-a")
inv.set_norma_didactica(20)
inv.set_vechime(3.7)
inv.afiseaza()
