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
class SaveToDb{
private:
ShoppingCart* cart;
public:
SaveToDb(ShoppingCart* cart)
{
    this->cart=cart;
}
bool add_to_sql_db()
{
 // db add logic
 bool success=true;
return success;
}
bool add_to_file()
{
    //file add logic
    return true;
}
};
int main()
{
    ShoppingCart* ash_shop_cart;
    ash_shop_cart->addProduct(new Product("Mouse",300));
    ash_shop_cart->addProduct(new Product("Keybord",400));
    cout<<ash_shop_cart->calculateTotal()<<endl;
    PrintCartInvoice* printer=new PrintCartInvoice(ash_shop_cart);
    SaveToDb* saver=new SaveToDb(ash_shop_cart);
    saver->add_to_file();
    printer->printInvoice();
    return 0;
}