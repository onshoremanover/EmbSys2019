//1.2 Die Datei muss im Directory mit "gcc testat1.c -o testat1" Kompiliert werden
//  Die Datei kann danach mit dem Befehl "./ testat1" oder "sudo ./testat1" ausgeführt werden.
// Dabei gibt printf auch direkt den output in die Kommandozeile ein

//1.3
// Verschiedene Maschinen/Computer von verschiedenen Herstellern haben verschiedene Maschinensprachbefehle.
// Deshalb muss das Kompilieren entweder direkt auf dem Endgerät ausgeführt werden, oder es wird das sogenannte Crosscompiling durchgeführt. Dabei wird die datei nicht auf dem Endgerät kompiliert, sondern speziell... danach ist das Programm jedoch nicht mehr auf der Erstellplatform ausführbar.

// Mit "$ arm- (TAB drücken) testat1.c -o testat1" kann die Datei für den Pi kompiliert werden. (ARM ist für den Maschinencode speziefisch)
// Das Kopieren der Datei auf den Pi wird mit "scp testat1 pi@w004-embsys-04.simple.eee.intern:~/" ausgeführt.
// Das Program wird dann in dem selben Verzeichnis mit "./testat1" ausgeführt.

#include <stdio.h>

int Zahl=1,Z2=1,Z3=1;

int main()
{
	while(Zahl<=20)
	{
		Z2=Zahl*Zahl;
		Z3=Z2*Zahl;
		fprintf(stdout, " %d  %d  %d\n",Zahl,Z2,Z3);
		Zahl++;
	}
	return 0;
}


