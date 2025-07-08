#include  <bits/stdc++.h >
#include <Book.cpp>
#inculde <Custom_Exeption.cpp>
using namespace  std ;

class BookStore  {
    int currentYear   ,  mxYears  ;
    map  < string  ,int   >  BooksStock ;
    map < string ,  Book>  RelatedBook ;     // the book related to some ISBN
public  :

      BookStore( ) {
         mxYears = 10 ;
      }

       BookStore(int currentYear  ,int mx = 10) {
                this->currentYear = currentYear ;
                mxYears = mx ;
      }


      void addBook(string id ,int qu ,  string title , int year , double price   , string type = "Special") {
              if ( currentYear  -  year     > mxYears)  {
                       cout<<"outdated Book !\n" ;
                       return ;
              }
             Book book(id , title ,  year , price , type) ;
             RelatedBook[id] = book  ;
             BooksStock[id] +=qu ;
             cout <<"Book Added succefully \n"  ;
      }

      //it keeps my stock of Books updated
      void ReturnAndRemove()  {
              map <string , bool >  del ;
              for (auto [bookISBN , cnt]  :BooksStock)  {
                       Book  book =  RelatedBook[bookISBN] ;
                       if (  currentYear  - book.getYear()    >mxYears)  {
                                 del[bookISBN]  = 1;
                       }
              }

              for (auto [bookID , kk]  : del)  {
                        BooksStock.erase(bookID) ;
              }
      }

    // if we have customer class it should have it's But that call this after check balance...
      double BuyBook(string ISBN , int quantity  , string Email , string address) {
                 if (BooksStock[ISBN]  < quantity)  {
                              throw Custom_Exeption("Invalid Quantity \n") ;
                              return  0;
                 }


                 Book book =  RelatedBook[ISBN] ;
                 cout<<book.getType()<<"\n" ;
                 if (book.getType()  == "Special")  {
                     throw Custom_Exeption("Can't Buy this Book  , Special Book\n") ;
                     return  0  ;
                 }

                 if(book.getType() == "Paper")  {
                        //shippingService(book ,  address) ;
                 }else if (book.getType() == "Ebook")  {
                        //MailService(book , mail)
                 }
                 BooksStock[ISBN] -=quantity;
                 cout<<"Sucessfuly operation wait for the delvirment \n" ;
                 return book.getPrice()   ;
      }


      void DisplayBooks()  {
               cout<<"*************Available Books \n" ;
               int c= 0 ;
               for (auto [ISBN ,  cnt]  : BooksStock)  {
                        if (cnt == 0 ) continue;
                        c++  ;
                        Book book = RelatedBook[ISBN] ;
                        cout<<ISBN <<" "<<book.gettitle()<<"|  "<<book.getType() <<"| "<<book.getYear() <<" "<<book.getPrice() <<"\n" ;

                }
               if (c== 0)  {
                      cout<<"Sorry  We don't have available right now\n" ;
               }
               cout<<"\n-----------------------------------\n"  ;
      }
};
