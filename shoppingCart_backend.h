#include<string>
#include<unordered_map>
using namespace std;
//We're gonna make classes for product, items and cart

class product{
    int id;
    string name;
    float price;

    public:
    product(){} //parameterized
    product(int id,string name,float price){
        this->id=id;
        this->name=name;
        this->price=price;
    }

    string getProductinfo(){
        return "("+to_string(id)+")"+name+ ", Rs: " + to_string(price)+'\n';
    }

    bool check(int id){
        if(this->id==id){
            return true;
        }
        return false;
    }
    friend class item;
    friend class cart;
};

class item{
    product p;
    int quantity;
    public:
    item(){}
    item(product pro,int q): p(pro),quantity(q){} //initialisation list

    float getprice(){
        return quantity*p.price;
    }

    string getiteminfo()
    {
        return to_string(quantity)+" x "+p.name+", Rs:"+to_string(p.price*quantity)+'\n';
    }
    friend class cart;
};

class cart{
    unordered_map<int,item> items;
    public:

    void additems(product p){
        if(items.count(p.id)==0){
            item new_item(p,1);
            items[p.id]=new_item;
        }
        else
        {
            items[p.id].quantity+=1;
        }
    }
    int calculate_total(){
        int total=0;
            for(auto x:items)
            total+=x.second.getprice();
        
        return total;
        }
    string viewcart(){
        
        if(items.empty()){
            return "cart is empty";
        }
        
        
        int total_amount=calculate_total();
        string ListofItems;
        int i=1;
        for(auto x:items){
            ListofItems.append("item no."+to_string(i)+" "+x.second.getiteminfo());
        }
        return ListofItems+'\n'+"total amount: "+to_string(total_amount)+'\n';
    }

    bool isEmpty(){
        return items.empty();
    }


};
