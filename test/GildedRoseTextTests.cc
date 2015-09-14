#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PulseTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "GildedRose.h"

#define RESULTS_FILENAME "test/goldmaster-results.txt"

using namespace std;

BOOST_AUTO_TEST_SUITE(UnitTestsSuite)

ostream& operator<<(ostream& s, Item& item)
{
    s << item.name << ", " << item.sellIn << ", " << item.quality;
    return s;
}

string read_file_results()
{
    ifstream inFile;
    inFile.open(RESULTS_FILENAME);

    if (!inFile.good()) return "";

    stringstream strStream;
    strStream << inFile.rdbuf();
    string str = strStream.str();
    return str;
}

BOOST_AUTO_TEST_CASE(exampleTest)
{
    stringstream ss;

    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    // this Conjured item doesn't yet work properly
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);

    ss << "OMGHAI!" << endl;

    for (int day = 0; day <= 30; day++)
    {
        ss << "-------- day " << day << " --------" << endl;
        ss << "name, sellIn, quality" << endl;
        for (vector<Item>::iterator i = items.begin(); i != items.end(); i++)
        {
            ss << *i << endl;
        }
        ss << endl;

        app.updateQuality();
    }

    string results = read_file_results();
    if (results == "") {
        ofstream write(RESULTS_FILENAME);
        write << ss.str();
        write.close();
        
        BOOST_FAIL("First time the test is executed. Saved file with test results.");
    }

    BOOST_CHECK_EQUAL(results, ss.str());
}

BOOST_AUTO_TEST_SUITE_END()
