#include  <bits/stdc++.h >
using namespace  std ;

#include  <Book.cpp> 
#include  <BookStore.cpp>
int main () {


   BookStore Bookstore ;


    while(true)  {
        cout<<"Hi   Admin what u want me  to do ? \n";
        cout<<"------------------------------how can i help you ^_^-- -------------------------\n" ;
        cout<<"Enter 1 for Displaying available  || 2 for Updating  ||  3 for adding Book   || 4 for Buying Book\n"  ;

        int q ;
        cin >> q ;



        if (q==1) {
            Bookstore.DisplayBooks() ;
        }else if (q == 2)   {
              Bookstore.ReturnAndRemove();
        }else if (q==3)  {
               cout<<" Enter Data of Book   : ISBN quantity  title year price type \n" ;
               string ISBN , title  , type;
               int year , quantity;
               double price;
               cin >> ISBN >>    quantity  >> title  >> year >> price>> type;
               Bookstore.addBook(ISBN , quantity ,  title , year ,  price , type) ;
        }else   {
                 cout<<" Enter Data of Book ISBN quantity  Email/address \n" ;
               string ISBN  ;
               int quantity ;
               string email ,  address;
               cin >>  ISBN  >> quantity >> email >> address ;
               try {
                   Bookstore.BuyBook(ISBN, quantity, email, address);
               }catch( Custom_Exeption & ex)  {
                     cout << ex.getError() <<"\n" ;
               }


        }
    }

}
