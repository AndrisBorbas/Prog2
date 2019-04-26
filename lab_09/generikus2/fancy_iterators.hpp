/*
 * \file fancy_iterators.hpp
 *
 */

#ifndef FANCY_ITERATORS_HPP
#define FANCY_ITERATORS_HPP

/// counting iterator.
/// Végtelen számláló.
/// Olyan típusokra példányosítható, aminek van pre-inkremens operátora.
template <typename T>
class counting_iterator {
    T t;
public:
    /// Konstruktor
    /// @param t - kezdőérték
    counting_iterator(T t = T()) : t(t) {}

    /// Összehasonlító operátorok
    bool operator==(const counting_iterator& rhs) const { return t == rhs.t; }
    bool operator!=(const counting_iterator& rhs) const { return !operator==(rhs); }

    /// pre-inkremens
    /// csak hatékonyság miatt ref. visszatérésű
    /// értelmetlen balértékként használni
    const counting_iterator& operator++() { ++t; return *this; }

    /// post-inkremens
    counting_iterator operator++(int) {
        counting_iterator tmp = *this;  /// eltesszük a jelenlegi értéket
        operator++();
        return tmp;                     /// léptetés előttivel tér vissza
    }

    /// dereferálás
    /// nem engedjük balértékként használni, ne változtathassa meg a sorozatot
    const T& operator*() const { return t; }

    /// szelekció pointerrel, ami címet kell, hogy adjon
    /// csak formai, mert csak privát adattag lenne elérhető, így nem lehet használni
    const T* operator->() const { return &operator*(); }
};

#endif // FANCY_ITERATORS_HPP
