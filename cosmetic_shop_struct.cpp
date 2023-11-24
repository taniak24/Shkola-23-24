#include <iostream>
#include <algorithm>

using namespace std;

///DEV mode
bool DEV = true;

struct product
{
    string brand;
    string type;
    float price;
    string color;
    string flavour;
    string madeIn;
};

struct shop
{
    string name;
    int amount;

    product stock[100]; ///goods
};

void input_products(product& pr)
{
    cout << endl;
    cout << "Enter product data: " << endl << endl;

    cout << "Brand: ";
    getline(cin, pr.brand);

    cout << "Type: ";
    getline(cin, pr.type);

    cout << "Price: ";
    cin >> pr.price;

    cin.ignore(); ///to pass the enter

    cout << "Color: ";
    getline(cin, pr.color);

    cout << "Flavour: ";
    getline(cin, pr.flavour);

    cout << "Made in: ";
    getline(cin, pr.madeIn);
}

void input_shop(shop& sh)
{
    cout << endl;
    cout << "Enter shop data: " << endl << endl;

    cout << "Shop name: ";
    getline(cin, sh.name);

    cout << "The amount of products: ";
    cin >> sh.amount;

    cin.ignore();
    for(int i = 0; i < sh.amount; i++)
    {
        input_products(sh.stock[i]);
    }
}

void output_products(product& pr)
{
    cout << "Brand: " << pr.brand << endl;
    cout << "Type: " << pr.type << endl;
    cout << "Price: " << pr.price << endl;
    cout << "Color: " << pr.color << endl;
    cout << "Flavour: " << pr.flavour << endl;
    cout << "Made in: " << pr.madeIn << endl;
}

void output_shop(shop& sh)
{
    cout << "Shop name: " << sh.name << endl;
    cout << "The amount of products: " << sh.amount << endl;

    cout << "Product data: " << endl << endl;
    for(int i = 0; i < sh.amount; i++)
    {
        output_products(sh.stock[i]);
    }
}

void most_expensive_pr(shop* exp, int shop_count)
{
    float most_expensive = exp[0].stock[0].price; //start from the first product;
    int ind1 = 0, ind2 = 0;

    for(int i = 0; i < shop_count; i++)
    {
        for(int j = 0; j < exp[i].amount; j++)
        {
            if(most_expensive < exp[i].stock[j].price)
            {
                most_expensive = exp[i].stock[j].price;
                ind1 = i;
                ind2 = j;
            }
        }
    }
    cout << "The most expensive product: ";
    output_products(exp[ind1].stock[ind2]);
}

void cheapest_pr(shop* ch, int shop_count)
{
    float cheapest = ch[0].stock[0].price; //start from the first product;
    int ind1 = 0, ind2 = 0;

    for(int i = 0; i < shop_count; i++)
    {
        for(int j = 0; j < ch[i].amount; j++)
        {
            if(cheapest > ch[i].stock[j].price)
            {
                cheapest = ch[i].stock[j].price;
                ind1 = i;
                ind2 = j;
            }
        }
    }
    cout << "The cheapest product: ";
    output_products(ch[ind1].stock[ind2]);
}

void bubble_sort(product* pr, int n)
{
    bool swapped; //use for optimising

    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(pr[j].price > pr[j + 1].price)
            {
                swap(pr[j], pr[j + 1]);
                swapped = true;
            }
        }

        ///when finish sorting - breaks
        if(!swapped)
        {
            break;
        }
    }
}


void sort_shop_data(shop& sh)
{
    bubble_sort(sh.stock, sh.amount);
}

int main()
{
    product cosmetic[100];
    shop cosmetic_shop[100];

    const int N = 2;

    int shops_amount = 2;

    if(!DEV)
    {
        for(int i = 0; i < N; i++)
        {
            input_shop(cosmetic_shop[i]);
        }
    }
    else
    {
        cout << "Hard coded data: " << endl;  // When DEV mode is true

        //hard coded data for 1st shop
        cosmetic_shop[0] = {"Lilly", 4};
        cosmetic[0] = {"Loreal", "shampoo", 14.99, "white", "peach", "Paris"};
        cosmetic[1] = {"Fenti", "gloss", 65.70, "red", "unscented", "California"};
        cosmetic[2] = {"Garnier", "conditioner", 11.50, "green", "coconut", "France"};
        cosmetic[3] = {"Nivea", "lotion", 9.75, "pink", "no", "Germany"};
        //put the products in the array
        cosmetic_shop[0].stock[0] = cosmetic[0];
        cosmetic_shop[0].stock[1] = cosmetic[1];
        cosmetic_shop[0].stock[2] = cosmetic[2];
        cosmetic_shop[0].stock[3] = cosmetic[3];

        //hard coded data for 2nd shop
        cosmetic_shop[1] = {"DM", 3};
        cosmetic[4] = {"Maybeline", "lipgloss", 8.20, "light red", "no", "New York"};
        cosmetic[5] = {"Dior", "lipstick", 70, "red", "cherry", "USA"};
        cosmetic[6] = {"Golden rose", "nail polish", 6.70, "purple", "no", "USA"};
        //put the products in the array
        cosmetic_shop[1].stock[0] = cosmetic[4];
        cosmetic_shop[1].stock[1] = cosmetic[5];
        cosmetic_shop[1].stock[2] = cosmetic[6];
    }

    cout << endl;
    system("cls");

    for (int i = 0; i < N; i++)
    {
        //SORT THE PRODUCTS BY THEIR PRICES IN ASCENDING ORDER
        sort_shop_data(cosmetic_shop[i]);
        cout << endl;
        cout << "OUTPUT:" << endl;
        cout << "Shop data: " << endl << endl;
        output_shop(cosmetic_shop[i]);
    }

    //return the most expensive product
    cout << endl;
    most_expensive_pr(cosmetic_shop, shops_amount);
    //return the cheapest product
    cout << endl;
    cheapest_pr(cosmetic_shop, shops_amount);

    //sort the products by their prices in ascending order
    //sort_shop_data(cosmetic_shop[0]);

    return 0;
}
