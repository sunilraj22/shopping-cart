#include<bits/stdc++.h>
#include "shoppingCart_backend.h"
using namespace std;

vector<product> Product={
    product(1,"apple",26),
    product(2,"mango",40),
    product(3,"water bottle",20),
    product(4,"dragon fruit",198),
    product(5,"lollipop",10),
    product(6,"coke",90)
};
product* choose_product()
{
    for(auto x:Product){
        cout<<x.getProductinfo();
    }
    cout<<endl;
    int id;
    cout<<"enter the serial number of product you want to add in cart :";
    cin>>id;
    cout<<endl;
    for(int i=0;i<Product.size();i++){
        if(Product[i].check(id)){
            return &Product[i];
        }
    }
    cout<<"Product not in the list"<<endl;
    return NULL;
}
bool checkout(cart c){
    if(c.isEmpty()){
        return false;
    }

    float amount;
    cout<<"Enter amount to pay:-"<<" Rs:";
    cin>>amount;

    cout<<endl<<endl;
    float total=c.calculate_total();
    if(amount>=total){
        cout<<"change = Rs:"<<amount-total<<endl<<endl;
        cout<<"Thank you for shopping !"<<endl;
    }
    else
    return false;

}
int main()
{
    char c;
    cart Crt;
    
    cout<<"Shopping Cart by Jonathan"<<endl;

    while(true){
        cout<<"choose option: (a) Add item(type a)        (b) View cart(type b)        (c) Checkout(type c)"<<endl<<endl;
        
        cout<<"type your option: ";
        cin>>c;
        cout<<endl;
        if(c=='a'){
            //view all products + choose a product + add to cart 
            product* selected_product=choose_product();
            if(selected_product!=NULL){
                cout<<"Product added to cart   ||  details: ";
                cout<<selected_product->getProductinfo();
                Crt.additems(*selected_product);
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
        else if (c=='b'){
            string allitems=Crt.viewcart();
            cout<<allitems;
            cout<<"----------------------------------------------------------------------"<<endl;
        }

        else if(c=='c'){
            cout<<" Your selected Items: "<<endl;
            cout<<Crt.viewcart();
            if(checkout(Crt)){
                break;
            }
            else{
                cout<<"Error : Check out failed, please try again"<<endl<<endl;
                cout<<endl;
            }
            
        }
    }
    return 0;
}