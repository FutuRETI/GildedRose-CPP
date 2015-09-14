Specifica progetto Gilded Rose
==============================

Ciao e benvenuto nel team Gilded Rose. Come forse sai, siamo una piccola locanda con una posizione
privilegiata in una importante città e gestita da un'amichevole locandiera chiamata Allison.
Noi compriamo e vediamo solo i migliori prodotti!
Sfortunatamente, i nostri prodotti hanno un costante degrado di qualità mano a mano che si avvicinano
alla data di scadenza. Abbiamo quindi realizzato un sistema per aggiornare in modo intelligente il
nostro inventario. Questo sistema è stato sviuppato da uno sviluppatore che sa il fatto suo che si 
chiama Leeroy, che però ora è coinvolto in altre avventure. Il tuo compito è quello di aggiungere
nuove caratteristiche al nostro sistema in modo che la nostra locanda possa iniziare a vendere anche
nuove categorie di prodotti.
Ma prima un'introduzione al nostro sistema:

* Tutti i prodotti (items) hanno un valore SellIn che denota il numero di giorni entro i quali  dobbiamo vendere quel prodotto.
* Tutti i prodotti, poi, hanno un valore Quality che donota quanto il prodotto sia di valore.
* Alla fine di ogni giorno, il nostro sistema decrementa entrambi questi valori per tutti i nostri prodotti.

Molto semplice, vero? Beh, qui è dove le cose iniziano a diventare interessanti:

Quando la data di scadenza (sell by date) è passata, la Quality degrada a velocità doppia.
* La Quality di un prodotto non è mai negativa.
* Il prodotto "Aged Brie", in realtà, incrementa la propria Quality man mano che invecchia
* La Quality di un qualsiasi prodotto non è mai maggiore a 50.
* Il prodotto "Sulfuras", essendo un oggetto leggendario, non ha nessuna data di scadenza e la
  sua Quality non decresce mai.
* I "Backstage passes", come l'aged brie, aumenta la propria Quality mano a mano che ci si avvicina
  alla data di SellIn; la sua Quality incrementa di 2 quando ci sono 10 o meno giorni mancanti
  alla sua scadenza e incrementa di 3 quando mancano 5 o meno giorni alla scadenza. La Quality, però,
  precipita a 0 appena dopo il concerto (quindi superata la data di scadenza).

Abbiamo appena formato un nuovo contratto di forniture per prodotti "conjured". Questo nuovo contratto
necessita un aggiornamento del nostro sistema:

* Portfolio prodotti - I prodotti "Conjured" degradano la propria Quality con rapidità doppia
  rispetto agli altri prodotti standard.

* Retail service – ogni giorno abbiamo circa tra i 5 e i 10 clienti che comprano ciascuno dai 2
  ai 6 oggetti (l'esatto numero di clienti e l'esatto numero di oggetti comprati devono essere
  randomizzati). Se non disponiamo del prodotto che il nostro cliente ci chiede, noi non possiamo
  offrirgli nessun'altro prodotto, ma lasciamo che se ne vada senza acquistare il prodotto cercato.
       
* Supply service – ogni terzo giorno riceviamo una fornitura di un numero tra i 40 e i 60 nuovi
  prodotti (il tipo dei prodotti e il loro esatto numero devono essere entrambi randomizzati).
  Non è necessario comprare per forza tutti i prodotti della fornitura, ma possiamo di volta in volta
  scegliere quali prodotti comprare tra quelli offerti.

* Business rules – ogni prodotto ha un proprio valore. Quindi sulla base di questo valore è possibile
  per noi calcolare il purchasePrice (quanto dobbiamo pagare per acquistare questo prodotto dal
  fornitore) e l'offerPrice (quanto possiamo guadagnare quando vendiamo il prodotto).
  Le regole di calcolo per questi due prezzi sono le seguenti:
  ```
  purchasePrice = value * Quality
  offerPrice = value * Quality * 1.5
  ```
  Quindi, se compriamo un prodotto e lo rivendiamo immediatamente lo stesso giorno (ovvero quando la
  sua Quality non ha subito nessun cambiamento) guadagnao il 50%!!

Sentitevi liberi di fare ogni cambiamento che ritenete utile al metodo UpdateQuality e anche di 
aggiungere nuovo codice. Ma attenzione che tutto deve continuare a funzionare correttamente come
sta facendo ora! Però, non potete modificare la classe Items o le proprietà dei vari Item, questi
infatti sono stati sviluppati dal goblin che vedete lì nell'angolo che è super contrario e stra
suscettibile all'idea di condividere del codice! Se proprio ne sentite il bisogno potete trasformare
i metodi UpdateQuality e la proprietà Items in elementi statici, vi copriamo noi con il goblin
restio al cambiamento!!

Un ultimo chiarimento, un prodotto non può mai avere la propria Quality ad un valore superiore a 50,
tuttavia "Sulfuras", che è un oggetto leggendario, ha questa proprietà Quality impostata al valore
80 e per questo prodotto la Quality non si altera mai.
