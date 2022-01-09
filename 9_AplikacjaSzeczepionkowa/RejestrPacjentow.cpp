#include "RejestrPacjentow.h"
#include "Pacjent.h"


void RejestrPacjentow::rejestruj(Pacjent pacjent)
{
	rejestr.push_back(pacjent);
}

void RejestrPacjentow::zaloguj(std::string login, std::string haslo)
{
    czyZalogowany = false;

    for (std::vector<Pacjent>::iterator it = rejestr.begin(); it != rejestr.end(); ++it)
    {

        if (it->login.compare(login) == 0)
        {
            if (it->haslo.compare(haslo) == 0)
            {
                czyZalogowany = true;

                std::cout << "Logowanie poprawne. Witaj " + it->login + " (" + it->imie + " " + it->nazwisko + ")" << std::endl;
                zalogowanyPacjent = *it;

                ObslugaMenuZalogowany();
                return;
            }
        }
    }
}

bool RejestrPacjentow::czyLiczba(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool RejestrPacjentow::kontrolaDaty(std::string data)
{
    if (data.length() != 10)
    {
        std::cout << "Wymagany format: DD-MM-YYYY" << std::endl;
        return false;
    }

    std::string dzien = data.substr(0, 2);
    std::string miesiac = data.substr(3, 2);
    std::string rok = data.substr(6, 4);


    if (czyLiczba(dzien) == false)
    {
        std::cout << "Wymagany format: DD-MM-YYYY" << std::endl;
        return false;
    }

    if (czyLiczba(miesiac) == false)
    {
        std::cout << "Wymagany format: DD-MM-YYYY" << std::endl;
        return false;
    }

    if (czyLiczba(rok) == false)
    {
        std::cout << "Wymagany format: DD-MM-YYYY" << std::endl;
        return false;
    }

    if (std::stoi(dzien) > 31)
    {
        std::cout << "Miesiac nie ma tylu dni!" << std::endl;
    }

    if (std::stoi(miesiac) > 12)
    {
        std::cout << "Rok nie ma tylu miesiecy!" << std::endl;
    }

    if (std::stoi(rok) < 1918)
    {
        std::cout << "Wprowadz rok wiekszy niz 1918!" << std::endl;
    }

    std::string znak1 = data.substr(2, 1);
    std::string znak2 = data.substr(5, 1);

    if ((znak1 != "-") || (znak2 != "-"))
    {
        std::cout << "Wymagany format: DD-MM-YYYY" << std::endl;
    }

}

void RejestrPacjentow::ObslugaMenuZalogowany()
{
    int wybor;
    std::string data;
    while (true)
    {
        wyswietlMenuZalogowany();
        std::cin >> wybor;


        if (wybor == 1)
        {
            wypiszDaty();
        }
        else if (wybor == 2)
        {
            if (czyMogeZaszczepic())
            {
                std::cout << "Mozna zaszczepic" << std::endl;
            }
            else
            {
                std::cout << "Jeszcze nie mozna zaszczepic" << std::endl;
            }
        }
        else if (wybor == 3)
        {
            while (true)
            {
                std::cout << "Podaj date szczepienia w formacie DD-MM-YYYY: ";
                std::cin >> data;

                if (kontrolaDaty(data))
                {
                    break;
                }
            }
            zaszczep(data);
        }
        else if (wybor == 4)
        {
            if (czyWaznyCertyfikat())
            {
                std::cout << "Certyfikat szczepienia jest wazny." << std::endl;
            }
            else
            {
                std::cout << "Certyfikat szczepienia nie jest wazny." << std::endl;
            }
        }
        else if (wybor == 5)
        {
            wyloguj();
            break;
        }
        else if (wybor == 0)
        {
            exit(0);
        }
    }
}

void RejestrPacjentow::wyswietlMenu()
{
    std::cout << "Co chcesz zrobic? " << std::endl;
    std::cout << "1 - zaloguj" << std::endl;
    std::cout << "2 - zarejestruj" << std::endl;
    std::cout << "0 - wyjdz" << std::endl;
    
}

void RejestrPacjentow::wyswietlMenuZalogowany()
{
    std::cout << "Co chcesz zrobic? "<< std::endl;
    std::cout << "1 - pokaz daty moich szczepien" << std::endl;
    std::cout << "2 - sprawdz czy moge sie zaszczepic " << std::endl;
    std::cout << "3 - zaszczep" << std::endl;
    std::cout << "4 - sprawdz waznosc certyfikatu" << std::endl;
    std::cout << "5 - wyloguj" << std::endl;
    std::cout << "0 - wyjdz z programu" << std::endl;
}

void RejestrPacjentow::wyloguj()
{
    czyZalogowany = false;
}

void  RejestrPacjentow::wypiszDaty()
{
    for (std::string data : zalogowanyPacjent.datySzczepien)
    {
        std::cout << data << std::endl;
    }
}

void RejestrPacjentow::zaszczep(std::string data)
{
    zalogowanyPacjent.datySzczepien.push_back(data);
}


int RejestrPacjentow::DajLiczbeDniOdSzczepienia(std::string dataSzczepienia)
{
    int miesiacSzczepienia = std::stoi(dataSzczepienia.substr(3, 2));
    int dzienSzczepienia = std::stoi(dataSzczepienia.substr(0, 2));
    int rokSzczepienia = std::stoi(dataSzczepienia.substr(6, 4));
    std::string aktualnaData = currentDate();
    int aktualnyMiesiac = std::stoi(aktualnaData.substr(3, 2));
    int aktualnyDzien = std::stoi(aktualnaData.substr(0, 2));
    int aktualnyRok = std::stoi(aktualnaData.substr(6, 4));

    return liczbaDni(aktualnyRok, aktualnyMiesiac, aktualnyDzien, rokSzczepienia, miesiacSzczepienia, dzienSzczepienia);
}


bool RejestrPacjentow::czyMogeZaszczepic()
{
    int ileSzczepien = zalogowanyPacjent.datySzczepien.size();

    if (ileSzczepien == 0)
    {
        return true;
    }
    else if (ileSzczepien == 1)
    {
        std::string dataSzczepienia = zalogowanyPacjent.datySzczepien[0];

        DajLiczbeDniOdSzczepienia(dataSzczepienia);

        std::cout << DajLiczbeDniOdSzczepienia(dataSzczepienia) << std::endl;

        if (DajLiczbeDniOdSzczepienia(dataSzczepienia) >= 30 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (ileSzczepien >= 2)
    {
        std::string dataSzczepienia = zalogowanyPacjent.datySzczepien[zalogowanyPacjent.datySzczepien.size() - 1];

        std::cout << DajLiczbeDniOdSzczepienia(dataSzczepienia) << std::endl;

        if (DajLiczbeDniOdSzczepienia(dataSzczepienia) >= 30 * 6)
        {
            return true;
        }
        else
        {
            return false;
        }
            
    }
}

bool RejestrPacjentow::czyWaznyCertyfikat()
{
    if (zalogowanyPacjent.datySzczepien.size() == 0)
    {
        return false;
    }
    else
    {
        std::string dataOstatniegoSzczepienia = zalogowanyPacjent.datySzczepien[zalogowanyPacjent.datySzczepien.size() - 1];

        if ((zalogowanyPacjent.datySzczepien.size() >= 2) && (DajLiczbeDniOdSzczepienia(dataOstatniegoSzczepienia) > 12 * 30))
        {
            return true;
        }
        return false;
    }
}

std::tm RejestrPacjentow::make_tm(int year, int month, int day)
{
    std::tm tm = { 0 };
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}

int RejestrPacjentow::liczbaDni(int rok1, int miesiac1, int dzien1, int rok2, int miesiac2, int dzien2)
{
    std::tm tm1 = make_tm(rok1, miesiac1, dzien1);
    std::tm tm2 = make_tm(rok2, miesiac2, dzien2);

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const int seconds_per_day = 60 * 60 * 24;
    return (time1 - time2) / seconds_per_day;
}


std::string RejestrPacjentow::currentDate() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}