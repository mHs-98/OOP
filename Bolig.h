class Bolig {

private:
    int oppdragNr;
    string saksbehandler,
            eierNavn,
            addresse,
            beskrivelse;
public:
    Bolig();
    Bolig(ifstream &inn);
};
