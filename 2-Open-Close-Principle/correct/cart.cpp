#include <iostream>
#include <vector>
using namespace std;
class Product{
    public:
    string name;
    float price;
    Product(string name,float price){
        this->name=name;
        this->price=price;
    }
};
class ShoppingCart{
    public:
    vector<Product*> products;
    public:
    void addProduct(Product* p)
    {
          products.push_back(p);
    }
    const vector<Product*>& getProduct()
    {
        return products;
    } 
    float calculateTotal(){
        float total=0;
        for(auto it:products)
        {
            total+=it->price;
        }
        return total;
    }
    
    bool addDB()
    {
     //add to Db
     return true;
    }

};
class PrintCartInvoice{
    private:
    ShoppingCart* cart;
    public:
   PrintCartInvoice(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice()
    {
        cout<<"Shoping Cart Invoice\n";
        for(auto it:cart->getProduct())
        {
            cout<<"name"<<"---->"<<it->name<<"    "<<"price"<<"---->"<<it->price<<endl;

        }
    }
};
//Abstract Class
class Persistence{
    private:
    ShoppingCart* cart;
    public:
    virtual void save(ShoppingCart* cart)=0;
};
class SQLPersistence:public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving shoping info in sql"<<endl;
    }
};
class FilePersistence:public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"saved to mongo";
    }
};
int main()
{
    ShoppingCart* ash_shop_cart;
    ash_shop_cart->addProduct(new Product("Mouse",300));
    ash_shop_cart->addProduct(new Product("Keybord",400));
    cout<<ash_shop_cart->calculateTotal()<<endl;
    PrintCartInvoice* printer=new PrintCartInvoice(ash_shop_cart);
    printer->printInvoice();
    return 0;
}