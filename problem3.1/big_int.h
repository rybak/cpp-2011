#ifndef BIG_INT_H
#define BIG_INT_H

/*
rybak andrey
big_int.h with    digits_container
*/

#include <string>
#include "digits_container.h"

struct big_int_calc_error{};
struct big_int_factorial_error : big_int_calc_error{};
struct big_int_division_by_zero : big_int_calc_error{};
struct big_int_power_error : big_int_calc_error{};
struct big_int_constructor_bad_string{};


struct big_int
{
   explicit big_int(long long n = 0);
   explicit big_int(const std::string&);
   big_int(const big_int&);
   big_int& operator=(const big_int&);
   void swap(big_int&);

   /* I/O */
   friend std::ostream& operator<< (std::ostream&, const big_int&);
   //friend std::istream& operator>> (std::istream&, big_int&);

   /* compare */
   bool operator>(const big_int&) const;
   bool operator<(const big_int&) const;
   bool operator<=(const big_int&) const;
   bool operator>=(const big_int&) const;
   bool operator==(const big_int&) const;
   bool operator!=(const big_int&) const;

   /* arithmetic */
   big_int operator-() const;

   big_int& operator+=(const big_int&);
   big_int& operator-=(const big_int&);
   big_int& operator*=(long long);
   big_int& operator*=(const big_int&);

   big_int& operator<<=(size_t);
   big_int& operator>>=(size_t);

   std::pair<big_int, big_int> divmod(const big_int&) const;
   big_int& operator/=(const big_int&);
   big_int& operator%=(const big_int&);

   big_int& operator++();

   static const big_int ZERO, ONE, TWO, TEN;
   
private:
   static const long long base = 1000000000;
   static const size_t base_length = 9;
   //typedef std::vector<long long> digits_container;
   digits_container digits_;

   bool negative_;

   size_t size() const;

   int compare_to(const big_int&) const;
   int abs_compare(const big_int&) const;

   void cut_leading_zeros();
};
/*
*/
big_int operator+(const big_int&, const big_int&);
big_int operator-(const big_int&, const big_int&);
big_int operator*(const big_int&, long long);
big_int operator*(long long, const big_int&);
big_int operator*(const big_int&, const big_int&);
big_int operator/(const big_int&, const big_int&);
big_int operator%(const big_int&, const big_int&);

big_int power(big_int, big_int);

big_int abs(big_int&);

std::istream& operator>> (std::istream&, big_int&);

// END big_int.h

#endif
