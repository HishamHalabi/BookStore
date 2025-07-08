#include  <bits/stdc++.h >
using namespace  std ;
class Book  {
      string ISBN   ;
      string title    ;
      int year  ;
      double price  ;

      string type ;    //  Paper   , Ebook  , special (showcase ,  Demo)

public:
       Book() {}
      Book(string ISBN ,  string title , int year   , double price  , string type = "special") {
            this->ISBN =ISBN ;
            this->title = title ;
            this->year = year;
            this->price = price ;
            this->type = type;
      }

      string getISBN()  {
             return ISBN;
      }

      string gettitle() {
            return title ;
      }

      int  getYear() {
            return year ;
      }

      double getPrice() {
            return price ;
      }

    // for future changes
      void SetPrice(double p) {
             price =  p ;
      }

      string getType() {
            return type ;
      }

     // to support map we should add this and it's sort them by year on map
      bool operator<  (const Book &other)  {
             return this-> year   < other.year;
      }
};
