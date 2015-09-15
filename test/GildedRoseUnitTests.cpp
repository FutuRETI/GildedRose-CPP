#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PulseTest
#include <boost/test/unit_test.hpp>
#include <string>
#include "GildedRose.h"

/**
 * Questa classe contieiene un esempio di un test che potrete utilizzare come "traccia"
 * per l'implementazione dei vostri nuovi casi di test.
 * 
 * Come vedete il metodo di test (in questo caso chiamato foo) è suddiviso in tre parti distinte:
 * - given: è una parte preparatoria al caso di test vero e proprio, in questa parte del metodo
 *   vengono create tutte le precondizioni necessarie a permettere l'esecuzione del test vero
 *   e proprio
 * - when: è la parte in cui viene eseguita l'operazione che si sta testando; configurate tutte le
 *   precondizioni in questa parte viene eseguita una specifica funzionalità sotto test (in questo
 *   caso viene eseguito il metodo UpdateQuality)
 * - then: è l'ultima parte del test e contiene le ferifiche che devono essere fatte per accertarsi
 *   che la funzionalità sotto test abbia prodotto i risultati attesi (in questo caso è presente
 *   un'Assert che non verifica nessuna caratteristica rilevante del metodo UpdateQuality, ma test
 *   reali dovranno invece verificare proprietà significative della funzionalità testata).
 *   
 * Consigliamo di sviluppare tutti i test mantenendo questa struttura (proprio comprensiva anche delle
 * tre righe di commento che permettano di identificare le varie parti del metodo di test).
 **/

using namespace std;

BOOST_AUTO_TEST_SUITE(UnitTestsSuite)

BOOST_AUTO_TEST_CASE(exampleTest)
{
    // given
    string itemName = "foo";
    int itemSellIn = 0;
    int itemQuality = 0;

    vector<Item> items;
    items.push_back(Item(itemName, itemSellIn, itemQuality));
    GildedRose app(items);

    // when
    app.updateQuality();

    // then
    BOOST_CHECK_EQUAL(itemName, app.items[0].name);
}

BOOST_AUTO_TEST_SUITE_END()
