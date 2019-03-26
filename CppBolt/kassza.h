#ifndef KASSZA_H
#define KASSZA_H

/**
 * \file kassza.h
 *
 * Kassza osztály deklarációja és inline függvényei
 */

#include "aru.h"
#include "datum.h"


/// Tetel publikus osztály: Kassza ilyen tételeket tárol.
/// Kassza belső osztálya is lehetne, de talán így jobban olvasható
struct Tetel {
    double mennyiseg;   ///< eladott áru mennyisége
    const Aru* aru;     ///< eladott áru. POINTER az ős osztályra!
    Datum  datum;       ///< eladás dátuma

    Tetel() :mennyiseg(0), aru(NULL) {}
    Tetel(double mennyi, const Aru* aru, const Datum& d
          )
        :mennyiseg(mennyi), aru(aru), datum(d) { }
};

/// Kassza osztály.
/// Fix darabszámú Tetel tárolására képes.
/// Ha betelik, const char* kivételt dob
class Kassza {
    size_t db;          ///< tarolt darabszám
    static const size_t maxdb = 20;  ///< méret
    Tetel tetelek[maxdb];   /// taroló. Tetel-eket tárol
  public:

    /// Üres kassza
    Kassza() :db(0) {}

    /// Eladás.
    /// @param mennyi - eladott mennyiség
    /// @param mit  - referencia az eladott árura (Kompatibilitás kihasználása)
    /// @param mikor - eladás dátuma
    /// @return kivételt dob, ha nem fér be
    void elad(double mennyi, const Aru& mit, const Datum& mikor = Datum());

    /// Kassza tartalmának kilistázása
    /// @param os - output stream
    void list(std::ostream& os) const;

    /// Eladások listázása egy adott napon
    /// @param os - output stream
    /// @param mikor - melyik nap
    void list(std::ostream& os, const Datum& mikor) const;

    /// Eladások összege egy adott napra
    /// @param mikor - melyik nap
    /// @return - összeg
    double napiOsszeg(const Datum& mikor = Datum());
};

#endif // KASSZA_H

