#include "../../json2XML.cpp"

using namespace std;

int main(void) {
    string json = "\"users\":[\"user\":{\"id\":\"1\",\"name\":\"AhmedAli\",\"posts\":[\"post\":{\"body\":\"Loremipsumdolorsitamet,consecteturadipiscingelit,seddoeiusmodtemporincididuntutlaboreetdoloremagnaaliqua.Utenimadminimveniam,quisnostrudexercitationullamcolaborisnisiutaliquipexeacommodoconsequat.\",\"topics\":[\"topic\":\"economy\",\"topic\":\"finance\",],}\"post\":{\"body\":\"Loremipsumdolorsitamet,consecteturadipiscingelit,seddoeiusmodtemporincididuntutlaboreetdoloremagnaaliqua.Utenimadminimveniam,quisnostrudexercitationullamcolaborisnisiutaliquipexeacommodoconsequat.\",\"topics\":{\"topic\":\"solar_energy\",}}],\"followers\":[\"follower\":{\"id\":\"2\",}\"follower\":{\"id\":\"3\",}],}\"user\":{\"id\":\"2\",\"name\":\"YasserAhmed\",\"posts\":{\"post\":{\"body\":\"Loremipsumdolorsitamet,consecteturadipiscingelit,seddoeiusmodtemporincididuntutlaboreetdoloremagnaaliqua.Utenimadminimveniam,quisnostrudexercitationullamcolaborisnisiutaliquipexeacommodoconsequat.\",\"topics\":{\"topic\":\"education\",}}}\"followers\":{\"follower\":{\"id\":\"1\",}}}],";
    cout << json2XML_Converter(json);
}