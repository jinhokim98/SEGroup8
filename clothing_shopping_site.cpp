#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <tuple>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile(INPUT_FILE_NAME);   // input.txt �� �б���� ����
ofstream outputFile(OUTPUT_FILE_NAME); // output.txt �� ������� ����

/*
Class: SignUp
Description: ȸ������ ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class SignUp
{
private:

public:
    SignUp();
    void ProceedSignUp();
    void GetEssentailInfo(string inputMemberName, string inputIDCardNumber, string inputID, string inputPW);
};

/*
Class: SignUpUI
Description: ȸ������ �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class SignUpUI
{
private:

public:
    void PushSignUpButton(SignUp* signUp);
    void ShowEssentialInfoInputInterface();
    void InputEssentialInfo(SignUp* signUp);
    void ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW);
};

/*
Class: DeleteMyAccount
Description: ȸ��Ż�� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class DeleteMyAccount
{
private:

public:
    DeleteMyAccount();
    void DeleteAccount();

};

/*
Class: DeleteMyAccountUI
Description: ȸ��Ż�� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class DeleteMyAccountUI
{
private:

public:
    void DeleteAccountButton(DeleteMyAccount* deleteMyAccount);
    void ShowCompleteDeleteAccount(string id);
};

/*
Class: Login
Description: �α��� ��Ʈ�� Ŭ���� �̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Login
{
private:

public:
    Login();
    bool IDPWinputed(string inputID, string inputPW);
};

/*
Class: LoginUI
Description: �α��� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class LoginUI
{
private:

public:
    bool InputIDPW(Login* login);
    void ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW);
};

/*
Class: Logout
Description: �α׾ƿ� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Logout
{
private:

public:
    Logout();
    void DoLogout();
};

/*
Class: LogoutUI
Description: �α׾ƿ� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class LogoutUI
{
private:

public:
    void PushLogoutButton(Logout* logout);
    void ShowCompleteLogoutMessage();
};

/*
Class: AddProduct
Description: �Ǹ��Ƿ���� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class AddProduct
{
private:

public:
    AddProduct();
    void ShowAddUI();
    void SendProductData(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);
};

/*
Class: AddProductUI
Description: �Ǹ��Ƿ���� �ٿ���� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class AddProductUI
{
private:

public:
    void AddProductButton(AddProduct* addProduct);
    void StartInterface();
    void InputProductData(AddProduct* addProduct);
    void ShowRegistrationCompleteMessage(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);
};

/*
Class: ViewProduct
Description: �Ǹ��Ƿ���ȸ ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ViewProduct
{
private:

public:
    ViewProduct();
    void ShowSellingProduct();

};

/*
Class: ViewProductUI
Description: �Ǹ��Ƿ���ȸ �ٿ���� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ViewProductUI
{
private:

public:
    void ViewSalesProductButton(ViewProduct* viewProduct);
    void ShowRegistedProductInfo(string productName, string productMadeCompanyName, int productPrice, int productCount);

};

/*
Class: ViewSoldoutProduct
Description: �ǸſϷ��ǰ��ȸ ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ViewSoldoutProduct
{
private:

public:
    ViewSoldoutProduct();
    void ShowSoldoutProduct();
};

/*
Class: ViewSoldoutProductUI
Description: �ǸſϷ��ǰ��ȸ �ٿ���� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ViewSoldoutProductUI
{
private:

public:
    void ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct);
    void ShowSoldoutProductInfo(string productName, string madeCompanyName, int price, int sellingCount, double averageRating);
};

/*
Class: ProductSalesStats
Description: ��ǰ�Ǹ���� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ProductSalesStats
{
private:

public:
    ProductSalesStats();
    void ShowSalesStats();
};

/*
Class: ProductSalesStatsUI
Description: ��ǰ�Ǹ���� �ٿ���� Ŭ�����̴�.
Created: 2022/5/30 3:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class ProductSalesStatsUI
{
private:

public:
    void SalesStatsButton(ProductSalesStats* productSalesStats);
    void ShowProductSalesStats(string productName, int sum, double averageRating);
};

/*
Class: SearchProduct
Description: ��ǰ ���� �˻� ��Ʈ�� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class SearchProduct
{
private:

public:
    SearchProduct();
    void ShowProductInfo(string productName);
};

/*
Class: SearchProductUI
Description: ��ǰ ���� �˻� �ٿ���� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class SearchProductUI
{
private:

public:
    void ShowSearchWindow();
    void InputProductName(SearchProduct* searchProduct);
    void ShowSearchProductInfo(string sellerID, string productName, string madeCompanyName, int price, int remainCount, double averageRating);
};

/*
Class: PurchaseProduct
Description: ��ǰ ���� ��Ʈ�� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class PurchaseProduct
{
private:

public:
    PurchaseProduct();
    void ProceedPurchase();
};

/*
Class: PurchaseProductUI
Description: ��ǰ ���� �ٿ���� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class PurchaseProductUI
{
private:

public:
    void PushPurchaseButton(PurchaseProduct* purchaseProduct);
    void ShowPurchasedProductInfo(string sellerID, string productName);
};

/*
Class: PurchaseHistory
Description: ���� ���� ��ȸ ��Ʈ�� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class PurchaseHistory
{
private:

public:
    PurchaseHistory();
    void ShowPurchaseHistory();
};

/*
Class: PurchaseHistoryUI
Description: ���� ���� ��ȸ �ٿ���� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class PurchaseHistoryUI
{
private:

public:
    void PushPurchaseHistoryButton(PurchaseHistory* purchaseHistory);
    void ShowPurchaseHistories(string sellerID, string productName, string madeCompanyName, int productPrice, int productRemainCount, double averageRating);
};

/*
Class: RatingManagement
Description: ������ �Է� ��Ʈ�� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class RatingManagement
{
private:

public:
    RatingManagement();
    void SendPurchasedProduct();
    void SendRatingButton();
    void SendRating(string productName, int ratingValue);
};

/*
Class: RatingUI
Description: ������ �Է� �ٿ���� Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class RatingUI
{
private:

public:
    void SelectPurchasedProduct(RatingManagement* ratingManagement);
    void ActivateRatingButton();
    void PushRatingButton(RatingManagement* ratingManagement);
    void ShowRatingInputWindow();
    void CreateNewRating(RatingManagement* ratingManagement);
    void ShowRatingInfo(string sellerID, string productName, int ratingValue);
};

/*
Class: Rating
Description: ������ �����ϴ� entity Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class Rating
{
private:
    int ratingValue;    // ����
    string productName; // ��ǰ �̸�
    string writer;      // ���� ���

public:
    void NewRating(int ratingValue, string productName, string writer);
    int GetRating() { return ratingValue; }
};

/*
Class: Product
Description: ��ǰ�� �����ϴ� entity Ŭ����
Created: 2022/5/29 5:00 pm
Author: �迵��
mail: kys981207@naver.com
*/
class Product
{
private:
    string productName; // ��ǰ��
    string madeCompanyName; // ����ȸ���
    string sellerID; // �Ǹ���ID
    int price; // ����
    int productCount; // ��ǰ ����
    int remainCount; // ���� ����
    int sellingCount; // �Ǹŵ� ����

    vector <Rating*> ratingListPointer;  // �ش��ǰ�� ��������Ʈ ������

public:
    Product(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount); // ������
    string GetProductName() { return productName; } // ��ǰ�� ��ȯ
    string GetMadeCompanyName() { return madeCompanyName; } // ����ȸ��� ��ȯ
    string GetSellerID() { return sellerID; }   // �Ǹ���ID ��ȯ 
    int GetPrice() { return price; } // ���� ��ȯ
    int GetProductCount() { return productCount; }  // ��ǰ ���� ��ȯ
    int GetRemainCount() { return remainCount; }    // ���� ���� ��ȯ
    int GetSellingCount() { return sellingCount; }  // �Ǹŵ� ���� ��ȯ
    vector <Rating*> ListRating();

    void AddRating(Rating* newRating);
    int GetSum();
    double GetAverageRating();
    bool CheckSelectedProduct(string productName);
    bool OrderProduct();
    void RequestEnrollRating(int rating);
    void SoldoutProduct(Product* soldoutProduct);
};

/*
Class: Member
Description: ȸ�� ��ƼƼ Ŭ�����̴�.
Created: 2022/5/25 5:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Member
{
private:
    string id; // ȸ���� ID
    string pw; // ȸ���� ��й�ȣ
    string memberName; // ȸ���� �̸�
    string idCardNumber; // ȸ���� �ֹι�ȣ
    vector <Product*> purchasedProductListPointer;  // ������ ��ǰ��ü�� �ּҸ� �������ϴ� ����Ʈ��
    vector <Product*> sellingProductListPointer;    // �Ǹ����� ��ǰ��ü�� �ּҸ� �������ϴ� ����Ʈ��
    vector <Product*> soldoutProductListPointer;    // �ǸſϷ�� ��ǰ��ü�� �ּҸ� ����Ű�� ����Ʈ��
    vector <Product*> allSalesProductListPointer;   // �ǸſϷ�, �Ǹ��� ��� ��ǰ ��ü�� �ּҸ� ����Ű�� ����Ʈ��

public:
    string GetID() { return id; }  // ȸ���� id�� get�ϴ� �Լ�
    string GetPW() { return pw; }  // ȸ���� pw�� get�ϴ� �Լ�
    string GetMemberName() { return memberName; }  // ȸ���� �̸��� get�ϴ� �Լ�
    string GetIDCardNumber() { return idCardNumber; }  // ȸ���� �ֹι�ȣ�� get�ϴ� �Լ�
    int CheckIDPW(string inputID, string inputPW); // �Է¹��� id, pw�� ��Ī�Ǵ��� Ȯ���ϴ� �Լ�

    Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber); //������
    ~Member(); //�ı���

    void AddPurchaseProduct(Product* product);  // ������ ��ǰ�� ����Ʈ�� �߰��ϴ� �Լ�
    void AddNewProduct(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);    // �Ǹŵ���� ��ǰ�� ����Ʈ�� �߰��ϴ� �Լ�
    void AddRegistedNewProuduct(Product* newProduct);   // �Ǹ����� ��ǰ�� ����Ʈ�� �߰��ϴ� �Լ�
    void AddSoldoutProduct(Product* soldoutproduct);    // �ǸſϷ��� ��ǰ�� ����Ʈ�� �߰��ϴ� �Լ�
    void AddAllSalesProduct(Product* newProduct);   //  �Ǹ����� ��ǰ�� �ǸſϷ�� ��ǰ�� ����Ʈ�� �߰��ϴ� �Լ�

    vector <Product*> ListPurchasedProduct();   // ������ ��ǰ�� ����Ű�� ������ ����Ʈ (purchasedProductListPointer)�� get�ϴ� �Լ���
    vector <Product*> ListSellingProducts();    
    vector <Product*> ListSoldoutProducts();    
    vector <Product*> ListAllsalesProducts();   
};

vector < tuple<string, string, Member*> > memberLoginInfo;  // ������ ù���� id , �ι�° ���� pw , ����° ���� Member��ü�� �ּҸ�����Ű�� ������ ������ ����
Member* curLoginMember; // ���� �α������� ȸ���� ������ �������� ����
bool loginState = false;    //  ���� �α������̸� true �α׾ƿ����̸� false ������ �������� ����

Product* curSearchedProduct;  // ���� �˻��� ��ǰ�� �������� ����

/*
Function : Product::Product(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount) 
Description: �� �Լ��� Product Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters :
string inputProductName - �Էµ� ��ǰ��
string inputMadeCompanyName - �Էµ� ����ȸ���
string inputPrice - �Էµ� ����
string inputProductCount - �Էµ� ��ǰ����
Return Value : ����
Created: 2022/5/29 5:00 pm
Author: �迵��
*/
Product::Product(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)  
{
    sellerID = curLoginMember->GetID();
    productName = inputProductName;
    madeCompanyName = inputMadeCompanyName;
    price = inputPrice;
    productCount = inputProductCount;
    remainCount = productCount; // �����Ǿ������� ���� ���� = ����
    sellingCount = 0;   // �����Ǿ������� �� ���� = 0

    curLoginMember->AddRegistedNewProuduct(this);   // ���� �α��� �� ȸ���� �Ǹ����� ��ǰ�� ����Ʈ�� �߰��Ѵ�
    curLoginMember->AddAllSalesProduct(this);   // ���� �α��� �� ȸ���� �Ǹ�����/�ǸſϷ��� ��ǰ�� ����Ʈ�� �߰��Ѵ�
}

/*
Function : int Product::GetSum()
Description: �� �Լ��� �Ǹ��� ��ǰ�� �Ǹ� �Ѿ׸� ���ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : int
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
int Product::GetSum()
{
    int sum = 0;
    int price = this->GetPrice();
    int sellingCount = this->GetSellingCount();

    sum = price * sellingCount;
    return sum;
}

/*
Function : double Product::GetAverageRating()
Description: �� �Լ��� �Ǹ��� ��ǰ�� ��� ���Ÿ������� ���ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : double
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
double Product::GetAverageRating()
{
    double averageRating = 0;
    int sum = 0;
    int count = 0;

    vector <Rating*> listRating;

    listRating = this->ListRating();

    for (int i = 0; i < listRating.size(); i++)
    {
        count++;
        sum += listRating[i]->GetRating();
    }

    if (count == 0)
    {
        return 0;
    }
    else
    {
        averageRating = (double)sum / count;
        return round(averageRating);
    }
}

/*
Function : void Product::AddRating(Rating* newRating)
Description: �� �Լ��� ��ǰ�� ���� �������� ��ǰ ��ü�� ��������Ʈ�� �߰��ϴ� �Լ��Դϴ�.
Parameters : 
Rating* newRating - �߰��� ���� ������
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void Product::AddRating(Rating* newRating)
{
    (this->ratingListPointer).push_back(newRating);
}

/*
Function : Member::Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber)
Description: �� �Լ��� Member Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters :
string inputID - �Էµ� id
string inputPW - �Էµ� pw
string inputMemberName - �Էµ� ȸ���� �̸�
string inputIDCardNumber - �Էµ� �ֹι�ȣ
Return Value : ����
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
Member::Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber)
{
    id = inputID;
    pw = inputPW;
    memberName = inputMemberName;
    idCardNumber = inputIDCardNumber;

    memberLoginInfo.push_back({ this->GetID(), this->GetPW(), this }); // �Էµ� ȸ���� ������ MemberLoginInfo�� Ǫ���Ѵ�.
}

/*
Function : Member::~Member()
Description: �� �Լ��� Member Ŭ������ ��ü�� �ı��ϴ� �ı��� �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
Member::~Member()
{
    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);
        string pw = get<1>(memberLoginInfo[i]);
        Member* pointerOfAddress = get<2>(memberLoginInfo[i]);
        // MemberLoginInfo ���Ϳ� ����ִ� �� ��ü�� id, pw, ��ü�� �ּ� ������


        string idOfCurObject = this->GetID(); // ���� ����� ��ü�� id
        string pwOfCurObject = this->GetPW(); // ���� ����� ��ü�� pw
        Member* pointerOfCurObject = this; // ���� ����� ��ü�� �ּ� ������

        if (idOfCurObject == id && pwOfCurObject == pw && pointerOfCurObject == pointerOfAddress) // ���� ����� �������ִ� ������ MemberLoginInfo�κ��� �����.
        {
            memberLoginInfo.erase(memberLoginInfo.begin() + i);
            break;
        }
    }
}

/*
Function : void Member::AddNewProduct(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
Description: �� �Լ��� �Է¹��� ��ǰ��, ����ȸ���, ����, ������ ���δ�Ʈ Ŭ�������� �����ϴ� �Լ��Դϴ�.
Parameters : 
string inputProductName - �Է¹��� ��ǰ��
string inputMadeCompanyName - �Է¹��� ����ȸ���
int inputPrice - �Է¹��� ����
int inputProductCount - �Է¹��� ����
Return Value : void
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
void Member::AddNewProduct(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
{
    Product* newProduct = new Product(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount); // ���� ������ ��ǰ ��ü�� �����Ѵ�
}

/*
Function : void Member::AddRegistedNewProuduct(Product* newProduct)
Description: �� �Լ��� sellingPoductListPointer�� ���� ����� ��ǰ ��ü�� �߰��ϴ� �Լ��Դϴ�.
Parameters : 
Product* newProduct - �߰��� ��ǰ ��ü
Return Value : void
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
void Member::AddRegistedNewProuduct(Product* newProduct)
{
    sellingProductListPointer.push_back(newProduct); // sellingPoductListPointer�� ���� ����� ��ǰ ��ü�� �߰��Ѵ�
}

/*
Function : void Member::AddSoldoutProduct(Product* soldoutProduct)
Description: �� �Լ��� soldoutProductListPointer�� �ǸſϷ�� ��ǰ ��ü�� �߰��ϴ� �Լ��Դϴ�.
Parameters : 
Product* soldoutProduct - �ǸſϷ�� ��ǰ ��ü
Return Value : void
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
void Member::AddSoldoutProduct(Product* soldoutProduct)
{
    (this->soldoutProductListPointer).push_back(soldoutProduct); // soldoutProductListPointer�� �ǸſϷ�� ��ǰ ��ü�� �߰��Ѵ�
}

/*
Function : void Member::AddAllSalesProduct(Product* newProduct)
Description: �� �Լ��� allSalesProductListPointer�� �Ǹ����� ��ǰ�� �ǸſϷ�� ��ǰ ������� �Ǹ��ڰ� �Ǹ��ϴ� ��� ��ǰ ��ü�� �߰��ϴ� �Լ��Դϴ�.
Parameters : 
Product* newProduct - �߰��� ��ǰ ��ü
Return Value : void
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
void Member::AddAllSalesProduct(Product* newProduct)
{
    allSalesProductListPointer.push_back(newProduct); // allSalesProductListPointer�� ��ǰ ��ü�� �߰��Ѵ�
}

/*
Function : vector <Product*> Member::ListSellingProducts()
Description: �� �Լ��� �Ǹ����� ��ǰ�� ����Ű�� ������ ����Ʈ (sellingProductListPointer)�� ��ȯ���ִ� �Լ��Դϴ�. 
Parameters : void
Return Value : vector <Product*>
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
vector <Product*> Member::ListSellingProducts()
{
    return this->sellingProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

/*
Function : vector <Product*> Member::ListSoldoutProducts()
Description: �� �Լ��� �ǸſϷ�� ��ǰ�� ����Ű�� ������ ����Ʈ (soldoutProductListPointer)�� ��ȯ���ִ� �Լ��Դϴ�. 
Parameters : void
Return Value : vector <Product*>
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
vector <Product*> Member::ListSoldoutProducts()
{
    return this->soldoutProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

/*
Function : vector <Product*> Member::ListAllsalesProducts()
Description: �� �Լ��� �Ǹ����� ��ǰ�� �ǸſϷ�� ��ǰ ��θ� ����Ű�� ������ ����Ʈ (allSalesProductListPointer)�� ��ȯ���ִ� �Լ��Դϴ�. 
Parameters : void
Return Value : vector <Product*>
Created: 2022/5/25 4:00 pm
Author: �迵��
*/
vector <Product*> Member::ListAllsalesProducts()
{
    return this->allSalesProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

/*
Function : bool LoginUI::InputIDPW(Login* login)
Description: �� �Լ��� �α��ν� id�� pw�� �Է��ϴ� �Լ��Դϴ�.
Parameters : Login* login - �α��� Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool LoginUI::InputIDPW(Login* login)
{
    string inputID, inputPW;
    inputFile >> inputID >> inputPW;    // UI�� id, pw �Է�

    return login->IDPWinputed(inputID, inputPW);   //��Ʈ�� Ŭ�������� �Է��� id, pw ����
}

/*
Function : void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
Description: �� �Լ��� �α��� �Ϸ�� �α��� �� ȸ���� id�� pw�� ����ϴ� �Լ��Դϴ�.
Parameters :
string curLoginMemberID - �α��� �� ȸ���� id
string curLoginMemberPW - �α��� �� ȸ���� pw
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
{
    //�α����� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α����� ȸ���� ���̵� ��й�ȣ�� �ؽ�Ʈ�� ���)
    outputFile << "> " << curLoginMemberID << " " << curLoginMemberPW << endl;
}

/*
Function : Login::Login()
Description: �� �Լ��� Login Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
Login::Login()
{
    LoginUI* loginUI = new LoginUI;

    if (loginUI->InputIDPW(this))   // id pw�� �Է��Ѵ�. �α����� �����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �´°��) �α��� �Ѵ�.
    {
        loginState = true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->GetID(), curLoginMember->GetPW());
    }
}

/*
Function : bool Login::IDPWinputed(string inputID, string inputPW)
Description: �� �Լ��� UI�κ��� �Է¹��� id, pw�� ��Ʈ�� Ŭ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string inputID - �Էµ� id
string inputPW - �Էµ� pw
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool Login::IDPWinputed(string inputID, string inputPW)
{
    if (curLoginMember->CheckIDPW(inputID, inputPW) != -1) // id�� pw�� ��Ī�Ǹ�
    {
        curLoginMember = get<2>(memberLoginInfo[curLoginMember->CheckIDPW(inputID, inputPW)]); // ��Ī�� id,pw�� ȸ������ ���� �α������� ȸ���� ������ ������
        return true;    // �α��� �����ϹǷ� true ��ȯ
    }
    return false;   // �α��� �Ұ����ϸ� false ��ȯ
}

/*
Function : int Member::CheckIDPW(string inputID, string inputPW)
Description: �� �Լ��� �α����Ҷ� �Է¹��� id�� pw�� ���� ��Ī�� �Ǵ��� Ȯ���ϴ� �Լ��Դϴ�.
Parameters :
string inputID - �Էµ� id
string inputPW - �Էµ� pw
Return Value : int
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
int Member::CheckIDPW(string inputID, string inputPW)
{
    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);
        string pw = get<1>(memberLoginInfo[i]);
        if (id == inputID && pw == inputPW) // �Է��� id�� pw�� ��Ī �Ǹ�
        {
            return i; // �ε��� ��ȯ
        }
    }
    return -1; // ��Ī�� �Ǵ°��� ������ -1��ȯ
}

/*
Function : void LogoutUI::PushLogoutButton(Logout* logout)
Description: �� �Լ��� �α׾ƿ� ��ư�� ������ �α׾ƿ��� �����ϴ� �Լ��Դϴ�.
Parameters : Logout* logout - Logout ��ü�� �ּҸ� ����Ű�� ������
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LogoutUI::PushLogoutButton(Logout* logout)
{
    if (loginState)  // �α��� ���¿����� �α׾ƿ� �� �� �ִ�.
    {
        logout->DoLogout();
    }
}

/*
Function : void LogoutUI::ShowCompleteLogoutMessage()
Description: �� �Լ��� �α׾ƿ��� �Ϸ������� �α׾ƿ��� ȸ���� id�� ����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LogoutUI::ShowCompleteLogoutMessage()
{
    //�α׾ƿ��� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α׾ƿ��� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile << "> " << curLoginMember->GetID() << endl;
}

/*
Function : Logout::Logout()
Description: �� �Լ��� Logout ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
Logout::Logout()
{
    LogoutUI* logoutUI = new LogoutUI(); logoutUI->PushLogoutButton(this);
}

/*
Function : void Logout::DoLogout()
Description: �� �Լ��� �α׾ƿ��۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void Logout::DoLogout()
{
    LogoutUI* logoutUI = new LogoutUI;
    logoutUI->ShowCompleteLogoutMessage();
    curLoginMember = NULL;
    loginState = false;
}

/*
Function : void SignUpUI::PushSignUpButton(SignUp* signUp)
Description: �� �Լ��� ȸ������ ��ư ������ ȸ�������� �����ϴ� �Լ��Դϴ�.
Parameters : SignUp* signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::PushSignUpButton(SignUp* signUp)
{
    signUp->ProceedSignUp();
}

/*
Function : void SignUpUI::InputEssentialInfo(SignUp* signUp)
Description: �� �Լ��� ȸ���� �⺻����(id, pw, ȸ���̸�, ȸ���ֹι�ȣ)�� �Է��ϴ� �Լ��Դϴ�.
Parameters : SignUp* signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::InputEssentialInfo(SignUp* signUp)
{
    string inputID, inputPW, inputMemberName, inputIDCardNumber;
    inputFile >> inputMemberName >> inputIDCardNumber >> inputID >> inputPW;  // ȸ���� �⺻�����Է�

    signUp->GetEssentailInfo(inputMemberName, inputIDCardNumber, inputID, inputPW); // ȸ���� �⺻ ������ ��Ʈ�� Ŭ������ �ѱ�
}

/*
Function : void SignUpUI::ShowEssentialInfoInputInterface()
Description: �� �Լ��� ȸ���� �⺻������ �Է��ϴ� �������̽��� ȸ������ �����ִ� �Լ��Դϴ�
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::ShowEssentialInfoInputInterface()
{
    /*
    ȸ���� �⺻������ �Է��ϴ� â���� �̵��ϴ� �ڵ� ����(�̹����������� �ؽ�Ʈ�� ǥ�� �ϹǷ� �ڵ� ����)
    */
}

/*
Function : void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
Description: �� �Լ��� ȸ�������� �Ϸ��������� ȸ���� �̸�, ȸ���� �ֹι�ȣ, ȸ���� id, ȸ���� pw�� ����ϴ� �Լ��Դϴ�.
Parameters :
string memberName - ȸ���� �̸�
string memberIDCardNumber - ȸ���� �ֹι�ȣ
string memberID - ȸ���� id
string memberPW - ȸ���� pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
{
    // ȸ������ �Ϸ��ߴٴ� �޼��� ���� ���Ŀ� �°� ���
    outputFile << "> " << memberName << " " << memberIDCardNumber << " " << memberID << " " << memberPW << endl;
}

/*
Function : SignUp::SignUp()
Description: �� �Լ��� SignUp ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
SignUp::SignUp()
{
    SignUpUI* signUpUI = new SignUpUI;
    signUpUI->PushSignUpButton(this);
    signUpUI->InputEssentialInfo(this);
}

/*
Function : void SignUp::ProceedSignUp()
Description: �� �Լ��� ȸ�������� ����ؼ� �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUp::ProceedSignUp()
{
    SignUpUI* signUpUI = new SignUpUI;
    signUpUI->ShowEssentialInfoInputInterface();
}

/*
Function : void SignUp::GetEssentailInfo(string inputMemberName, string inputIDCardNumber, string inputID, string inputPW)
Description: �� �Լ��� �Է¹��� ȸ�����̸�, �ֹι�ȣ, �Էµ� id, �Էµ� pw ������ get�Ͽ� ȸ������ �۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string inputMemberName - �Է¹��� ȸ���� �̸�
string inputIDCardNumber - �Է¹��� ȸ���� �ֹι�ȣ
string inputID - �Է¹��� ȸ���� id
string inputPW - �Է¹��� ȸ���� pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUp::GetEssentailInfo(string inputMemberName, string inputIDCardNumber, string inputID, string inputPW)
{
    bool signupPossible = true; //ȸ������ �����ϸ� true �ƴϸ� false

    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);

        if (id == inputID)    // ���Ϳ� �Է��� id�� �����ϸ� id �ߺ��� �ȵǹǷ�
        {
            signupPossible = false; // ������ �Ұ����ϴ�.
        }
    }

    if (signupPossible)  // ȸ�������� �����ϸ� (=��ġ�� ���̵������) ȸ�������Ѵ�.
    {
        Member* m = new Member(inputID, inputPW, inputMemberName, inputIDCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(inputMemberName, inputIDCardNumber, inputID, inputPW);
    }
}

/*
Function : void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount* deleteMyAccount)
Description: �� �Լ��� ȸ��Ż�� ��ư�� ������ ȸ��Ż�� �����ϴ� �Լ��Դϴ�.
Parameters : DeleteMyAccount* deleteMyAccount - DeleteMyAccount Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount* deleteMyAccount)
{
    deleteMyAccount->DeleteAccount();
}

/*
Function : void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
Description: �� �Լ��� ȸ��Ż�� �Ϸ� ������ Ż���� ȸ���� id�� ����ϴ� �ռ��Դϴ�.
Parameters : string curMemberID - Ż���� ȸ���� id
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
{
    //ȸ��Ż�� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� ȸ��Ż���� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile << "> " << curMemberID << endl;
}

/*
Function : DeleteMyAccount::DeleteMyAccount()
Description: �� �Լ��� DeleteMyAccount Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
DeleteMyAccount::DeleteMyAccount()
{
    DeleteMyAccountUI* deleteMyAccountUI = new DeleteMyAccountUI;
    deleteMyAccountUI->DeleteAccountButton(this);
}

/*
Function : void DeleteMyAccount::DeleteAccount()
Description: �� �Լ��� ȸ��Ż�� �۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccount::DeleteAccount()
{
    if (loginState)  // ���� �α��� ���϶��� ȸ�� Ż�� �����ϴ�.
    {
        DeleteMyAccountUI* deleteMyAccountUI = new DeleteMyAccountUI;
        string curMemberID = curLoginMember->GetID();   // Ż���ϴ� ȸ���� ���̵� ����
        curLoginMember->~Member(); // ��ü �����Ѵ�.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI�� ȸ�� Ż�� �Ǿ��ٴ� â�� ����
        curLoginMember = NULL; // ���� �α������� ȸ�� ����.
        loginState = false; // �α׾ƿ����·� �����.
    }
}

/*
Function : AddProduct::AddProduct()
Description: �� �Լ��� AddProduct ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
AddProduct::AddProduct()
{
    if (loginState)  // �α��� �� ���� �� ���� �Ǹ� �Ƿ��� ��� �� ���ִ�.
    {
        AddProductUI* addProductUI = new AddProductUI;
        addProductUI->AddProductButton(this);
        addProductUI->InputProductData(this);
    }
}

/*
Function : void AddProductUI::AddProductButton(AddProduct* addProduct)
Description: �� �Լ��� �Ǹ��Ƿ���� ��ư�� �������� ��Ʈ�� Ŭ�������� �˷��ִ� �Լ��Դϴ�.
Parameters : 
AddProduct* addProduct - �˷��� ��Ʈ�� Ŭ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProductUI::AddProductButton(AddProduct* addProduct)
{
    addProduct->ShowAddUI();
}

/*
Function : void AddProduct::ShowAddUI()
Description: �� �Լ��� AddProduct UI�� �����޶�� ��û�ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProduct::ShowAddUI()
{
    AddProductUI* addProductUI = new AddProductUI;
    addProductUI->StartInterface();
}

/*
Function : void AddProductUI::StartInterface()
Description: �� �Լ��� AddProduct UI�� �����ִ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProductUI::StartInterface()
{
    /*
    ��ǰ�� ������ �Է��ϴ� â���� �̵��ϴ� �ڵ� ����(�̹����������� �ؽ�Ʈ�� ǥ�� �ϹǷ� �ڵ� ����)
    */
}

/*
Function : void AddProductUI::InputProductData(AddProduct* addProduct)
Description: �� �Լ��� �Ǹ��ڿ��� �Է¹��� ��ǰ�������� ��Ʈ�� Ŭ�������� �����ϴ� �Լ��Դϴ�.
Parameters : 
AddProduct* addProduct - ���� ������ ��Ʈ�� Ŭ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProductUI::InputProductData(AddProduct* addProduct)
{
    string inputProductName, inputMadeCompanyName;
    int inputPrice, inputProductCount;

    inputFile >> inputProductName >> inputMadeCompanyName >> inputPrice >> inputProductCount;   // ��ǰ��, ����ȸ���, ����, ������ ���Ϸ� ���� �Է¹޴´�.

    addProduct->SendProductData(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount); // �Է¹��� ������ ��Ʈ�� Ŭ������ �����ش�.
}

/*
Function : void AddProduct::SendProductData(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
Description: �� �Լ��� �Ǹ��ڿ��� �Է¹��� ��ǰ�������� ��� Ŭ�������� �����ϴ� �Լ��Դϴ�.
Parameters : 
string inputProductName - �Է¹��� ��ǰ��
string inputMadeCompanyName - �Է¹��� ����ȸ���
int inputPrice - �Է¹��� ����
int inputProductCount - �Է¹��� ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProduct::SendProductData(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
{
    curLoginMember->AddNewProduct(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount);   // ���� �α��� �� ȸ���� �� ��ǰ�� ����ϴ� �Լ��� ȣ���Ѵ�
    
    AddProductUI *addProduct;
    addProduct->ShowRegistrationCompleteMessage(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount); // ��ϿϷ��Ͽ��ٰ� �޼����� ������.
}

/*
Function : void AddProductUI::ShowRegistrationCompleteMessage(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
Description: �� �Լ��� �Ǹ� �Ƿ��� �� ����Ͽ��ٴ� �޽����� ����ϴ� �Լ��Դϴ�.
Parameters : 
string inputProductName - �Է¹��� ��ǰ��
string inputMadeCompanyName - �Է¹��� ����ȸ���
int inputPrice - �Է¹��� ����
int inputProductCount - �Է¹��� ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void AddProductUI::ShowRegistrationCompleteMessage(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
{
    outputFile << "> ";
    outputFile << inputProductName << " " << inputMadeCompanyName << " " << inputPrice << " " << inputProductCount << endl; // ������ ��ǰ ��ü�� �̸�, ����ȸ���, ����, ������ ����Ѵ�.
}

/*
Function : ViewProduct::ViewProduct()
Description: �� �Լ��� ViewProduct ��Ʈ�� Ŭ������ ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
ViewProduct::ViewProduct()
{
    if (loginState)  // �α��� ���¿����� �Ǹ����� �Ƿ��� ��ȸ �����ϴ�.
    {
        ViewProductUI* viewProductUI = new ViewProductUI; // ViewProductUI Ŭ������ �����Ѵ�

        viewProductUI->ViewSalesProductButton(this);
    }
}

/*
Function : void ViewProductUI::ViewSalesProductButton(ViewProduct* viewProduct)
Description: �� �Լ��� �Ǹ��Ƿ���ȸ ��ư�� �������� ��Ʈ�� Ŭ�������� �˷��ִ� �Լ��Դϴ�.
Parameters : 
ViewProduct* viewProduct - �˷��� ��Ʈ�� Ŭ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewProductUI::ViewSalesProductButton(ViewProduct* viewProduct)
{
    viewProduct->ShowSellingProduct();
}

/*
Function : void ViewProduct::ShowSellingProduct()
Description: �� �Լ��� �Ǹ����� �Ƿ� ��ǰ�� �����ִ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewProduct::ShowSellingProduct()
{
    vector <Product*> listSellingProducts;
    // listSellingProducts�� ListSellingProducts() �Լ��κ��� ���� �α����� ȸ���� �Ǹ����� ��ǰ�� �ּҵ��� �������ϴ� ����Ʈ�� ��ȯ�ޱ� ���� ������

    listSellingProducts = curLoginMember->ListSellingProducts(); // ���� �α����� ȸ���� �Ǹ����� ��ǰ ����Ʈ�� �޾ƿ´�

    for (int i = 0; i < listSellingProducts.size(); i++) // �� ��ǰ�� �ּ��� �����͵��� �޾ƿ����� �ݺ����� ���� �������� viewProductUI���� �����Ѵ�.
    {
        ViewProductUI *viewProductUI = new ViewProductUI;
        viewProductUI->ShowRegistedProductInfo(listSellingProducts[i]->GetProductName(), listSellingProducts[i]->GetMadeCompanyName(), listSellingProducts[i]->GetPrice(),listSellingProducts[i]->GetProductCount());
    }
}

/*
Function : void ViewProductUI::ShowRegistedProductInfo(string productName, string productMadeCompanyName, int productPrice, int productCount)
Description: �� �Լ��� �Ǹ����� �Ƿ���ǰ���� ���������� ����ϴ� �Լ��Դϴ�.
Parameters : 
string productName - �Ǹ����� ��ǰ �̸�
string productMadeCompanyName - �Ǹ����� ��ǰ ����ȸ���
int productPrice - �Ǹ����� ��ǰ ����
int productCount - �Ǹ����� ��ǰ ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewProductUI::ShowRegistedProductInfo(string productName, string productMadeCompanyName, int productPrice, int productCount)
{
    outputFile << "> ";
    outputFile << productName<< " " << productMadeCompanyName << " " << productPrice << " " << productCount << endl;
}

/*
Function : ViewSoldoutProduct::ViewSoldoutProduct()
Description: �� �Լ��� ViewSoldoutProduct ��Ʈ�� Ŭ������ ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
ViewSoldoutProduct::ViewSoldoutProduct()
{
    if (loginState)  // �α��� ���¿����� �ǸſϷ�� �Ƿ��� ��ȸ �����ϴ�.
    {
        ViewSoldoutProductUI* viewSoldoutProductUI = new ViewSoldoutProductUI; //ViewSoldoutProductUI Ŭ������ �����Ѵ�.

        viewSoldoutProductUI->ViewSoldoutProductButton(this);
    }
}

/*
Function : void ViewSoldoutProductUI::ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct)
Description: �� �Լ��� �ǸſϷ��ǰ������ȸ ��ư�� �������� ��Ʈ�� Ŭ�������� �˷��ִ� �Լ��Դϴ�.
Parameters : 
ViewSoldoutProduct* viewSoldoutProduct - �˷��� ��Ʈ�� Ŭ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewSoldoutProductUI::ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct)
{
    viewSoldoutProduct->ShowSoldoutProduct();
}

/*
Function : void ViewSoldoutProduct::ShowSoldoutProduct()
Description: �� �Լ��� �ǸſϷ�� �Ƿ� ��ǰ�� �����ִ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewSoldoutProduct::ShowSoldoutProduct()
{
    vector <Product*> listSoldoutProducts;
    vector <tuple <string, string, int, int, double> > v; // ��ǰ���� �������� ���� ���� �����̴�
 
    listSoldoutProducts = curLoginMember->ListSoldoutProducts(); // ���� �α����� ȸ���� �ǸſϷ�� ��ǰ ����Ʈ�� �޾ƿ´�

    for (int i = 0; i < listSoldoutProducts.size(); i++) // �� ��ǰ�� �ּ��� �����͵��� �޾ƿ����� �ݺ����� ���� �������� ����Ѵ�.
    {
        string productName = listSoldoutProducts[i]->GetProductName();
        string madeCompanyName = listSoldoutProducts[i]->GetMadeCompanyName();
        int price = listSoldoutProducts[i]->GetPrice();
        int sellingCount = listSoldoutProducts[i]->GetSellingCount();
        double averageRating = listSoldoutProducts[i]->GetAverageRating();
        v.push_back({ productName, madeCompanyName, price, sellingCount, averageRating });    
    }

    sort(v.begin(), v.end()); // ��ǰ���� ������������ �����Ѵ�.

    for (int j = 0; j < v.size(); j++)
    {
        ViewSoldoutProductUI *viewSoldoutProductUI = new ViewSoldoutProductUI;
        viewSoldoutProductUI->ShowSoldoutProductInfo(get<0>(v[j]), get<1>(v[j]), get<2>(v[j]), get<3>(v[j]), get<4>(v[j]));
    }
}

/*
Function : void ViewSoldoutProductUI::ShowSoldoutProductInfo(string productName, string madeCompanyName, int price, int sellingCount, double averageRating)
Description: �� �Լ��� �ǸſϷ�� ��ǰ���� ���������� ����ϴ� �Լ��Դϴ�.
Parameters : 
string productName - �ǸſϷ�� ��ǰ�� �̸�
string madeCompanyName - �ǸſϷ�� ��ǰ�� ����ȸ���
int price - �ǸſϷ�� ��ǰ�� ����
int sellingCount - �ǸſϷ�� ��ǰ�� �Ǹŵ� ����
double averageRating - �ǸſϷ�� ��ǰ�� ��� ���Ÿ�����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ViewSoldoutProductUI::ShowSoldoutProductInfo(string productName, string madeCompanyName, int price, int sellingCount, double averageRating)
{
    outputFile << "> ";
    outputFile << productName << " ";
    outputFile << madeCompanyName << " ";
    outputFile << price << " ";
    outputFile << sellingCount << " ";
    outputFile << averageRating << endl;
}

/*
Function : ProductSalesStats::ProductSalesStats()
Description: �� �Լ��� ProductSalesStats ��Ʈ�� Ŭ������ ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
ProductSalesStats::ProductSalesStats()
{
    if (loginState) //�α��� ���� Ȯ��
    {
        ProductSalesStatsUI* productSalesStats = new ProductSalesStatsUI; // ProductSalesStatsUI Ŭ������ �����Ѵ�.

        productSalesStats->SalesStatsButton(this);
    }
}

/*
Function : void ProductSalesStatsUI::SalesStatsButton(ProductSalesStats* productSalesStats)
Description: �� �Լ��� ��ǰ�Ǹ���� ��ư�� �������� ��Ʈ�� Ŭ�������� �˷��ִ� �Լ��Դϴ�.
Parameters : 
ProductSalesStats* productSalesStats - �˷��� ��Ʈ�� Ŭ����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ProductSalesStatsUI::SalesStatsButton(ProductSalesStats* productSalesStats)
{
    productSalesStats->ShowSalesStats();
}

/*
Function : void ProductSalesStats::ShowSalesStats()
Description: �� �Լ��� ������� �Ǹ��� ��� ��ǰ�� ���� ��踦 �����ִ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ProductSalesStats::ShowSalesStats()
{
    if (loginState)
    {
        vector <Product*> listAllSalesProduct;
        listAllSalesProduct = curLoginMember->ListAllsalesProducts(); //���� �α��ε� ȸ���� ��� ��ǰ ����Ʈ�� �����´�.

        for (int i = 0; i < listAllSalesProduct.size(); i++)
        {
            ProductSalesStatsUI *productSalesStatsUI = new ProductSalesStatsUI;
            if(listAllSalesProduct[i]->GetSellingCount() != 0)
            {
                productSalesStatsUI->ShowProductSalesStats(listAllSalesProduct[i]->GetProductName(), listAllSalesProduct[i]->GetSum(), listAllSalesProduct[i]->GetAverageRating());
            }
        }
    }
}

/*
Function : void ProductSalesStats::ShowSalesStats()
Description: �� �Լ��� ������� �Ǹ��� ��� ��ǰ�� ���� ����� ������������ ����ϴ� �Լ��Դϴ�.
Parameters : 
string productName - ��ǰ��
int sum - ��ǰ �Ѿ�
double averageRating - ��� ���Ÿ�����
Return Value : void
Created: 2022/5/30 4:00 pm
Author: �迵��
*/
void ProductSalesStatsUI::ShowProductSalesStats(string productName, int sum, double averageRating)
{
    outputFile << "> ";
    outputFile << productName << " ";
    outputFile << sum << " ";
    outputFile << averageRating << " ";
    outputFile << endl;
}

/*
Function : SearchProduct::SearchProduct()
Description: �� �Լ��� SearchProduct Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
SearchProduct::SearchProduct()
{
    SearchProductUI* searchProductUI = new SearchProductUI;
    searchProductUI->ShowSearchWindow();
    searchProductUI->InputProductName(this);
}

/*
Function : SearchProductUI::ShowSearchWindow()
Description: �˻� â�� �����ִ� �Լ�, ���������� �ؽ�Ʈ�̱� ������ �ƹ� ��ɵ� �������� �ʴ´�.
Parameters : void
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void SearchProductUI::ShowSearchWindow()
{

}

/*
Function : SearchProductUI::InputProductName()
Description: ��ǰ �̸��� �Է¹޴� �Լ�
Parameters : SearchProduct* searchProduct
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void SearchProductUI::InputProductName(SearchProduct* searchProduct)
{
    string productName;             // ��ǰ��

    inputFile >> productName;

    // if�� ��ǰ �ִ��� ������ �˻��ڵ� �߰�
    searchProduct->ShowProductInfo(productName);
}

void SearchProductUI::ShowSearchProductInfo(string sellerID, string productName, string madeCompanyName, int price, int remainCount, double averageRating)
{
    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << " ";
    outputFile << madeCompanyName << " ";
    outputFile << price << " ";
    outputFile << remainCount << " ";
    outputFile << averageRating;
    outputFile << endl;
}

/*
Function : SearchProduct::ShowProductInfo()
Description: ��ǰ�� �̸��� �Է¹޾Ƽ� ��ǰ�� ������ ����ϴ� �Լ�
Parameters : string productName
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void SearchProduct::ShowProductInfo(string productName)
{
    vector <Product*> listSellingProducts;

    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        listSellingProducts.clear();    // �� �ݺ����� listSellingProducts ����Ʈ �ʱ�ȭ

        Member* member = get<2>(memberLoginInfo[i]);    // �ݺ����� ���� ��� �� ȸ������  

        listSellingProducts = member->ListSellingProducts();    // �Ǹ����� ��ǰ�� �ּ� �����͸� �޾ƿ�

        for (int j = 0; j < listSellingProducts.size(); j++)
        {
            if (listSellingProducts[j]->CheckSelectedProduct(productName) == true)
            {
                SearchProductUI *searchProductUI = new SearchProductUI;

                searchProductUI->ShowSearchProductInfo(listSellingProducts[j]->GetSellerID(), listSellingProducts[j]->GetProductName(), listSellingProducts[j]->GetMadeCompanyName(), listSellingProducts[j]->GetPrice(), listSellingProducts[j]->GetRemainCount(), listSellingProducts[j]->GetAverageRating());

                curSearchedProduct = listSellingProducts[j];  // ���� �˻��� ��ǰ���� ���������� ����

                return;
            }
        }
    }
    curSearchedProduct = NULL;
    return;
}

/*
Function : Product::CheckSelectedProduct()
Description: �˻��� ��ǰ�� �̸��� ��ϵǾ��ִ� ��ǰ�� �̸��� ������ ���ϴ� �Լ�
Parameters : string productName
Return Value : boolean (������ true, �ٸ��� false)
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
bool Product::CheckSelectedProduct(string productName)
{
    if (this->productName == productName && this->GetRemainCount() > 0)
        return true;
    else
        return false;
}

/*
Function : PurchaseProduct::PurchaseProduct()
Description: ��ǰ ���� ��Ʈ�� Ŭ����
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
PurchaseProduct::PurchaseProduct()
{
    PurchaseProductUI* purchaseProductUI = new PurchaseProductUI;
    purchaseProductUI->PushPurchaseButton(this);
}

/*
Function : PurchaseProductUI::PushPurchaseButton()
Description: ȸ���� ���� ��ư�� ����
Parameters : PurchaseProduct* purchaseProduct
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseProductUI::PushPurchaseButton(PurchaseProduct* purchaseProduct)
{
    purchaseProduct->ProceedPurchase();
}

/*
Function : PurchaseProductUI::ShowPurchasedProductInfo()
Description: ������ ��ǰ�� �Ǹ��ڿ� ��ǰ�̸��� ������ִ� �Լ��̴�.
Parameters : string sellerID - �Ǹ���ID
             string productName - ��ǰ�̸�
Return Value : void
Created: 2022/6/2 7:48 pm
Author: ����ȣ
*/
void PurchaseProductUI::ShowPurchasedProductInfo(string sellerID, string productName)
{
    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << endl;
}

/*
Function : PurchaseProduct::ProceedPurchase()
Description: ��Ʈ�� Ŭ������ ��ư ���� �� ����
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseProduct::ProceedPurchase()
{
    if (curSearchedProduct->OrderProduct() == true) // �ش� ��ǰ�� �ֹ��Ѵ�.
    {
        curLoginMember->AddPurchaseProduct(curSearchedProduct); // ������ ��ǰ����Ʈ�� �߰�

        PurchaseProductUI *purchaseProductUI = new PurchaseProductUI;
        purchaseProductUI->ShowPurchasedProductInfo(curSearchedProduct->GetSellerID(), curSearchedProduct->GetProductName());

    }
}

/*
Function : Member::AddPurchaseProduct()
Description: ȸ���� ������ ��ǰ ����Ʈ�� �߰��Ѵ�.
Parameters : Product* product
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void Member::AddPurchaseProduct(Product* product)
{
    this->purchasedProductListPointer.push_back(product);
}

/*
Function : Product::orderProduct()
Description: ������ ��ǰ�� ���� �ֹ��� �ִ� �Լ�
Parameters : ����
Return Value : boolean (��� ������ true, ������ false)
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
bool Product::OrderProduct()
{
    if (remainCount > 0)
    {
        remainCount--;  // ��ǰ�� �����߱� ������ ��� �ϳ��� ����.

        sellingCount++; //��ǰ�� �����߱� ������ ���ż��� �ϳ� �ø���.

        if (remainCount == 0)
        {
            this->SoldoutProduct(this);
        }
        return true;
    }
    else
        return false;
}

/*
Function : Product::SoldoutProduct()
Description: �ǸŰ� �Ϸ�Ǿ� ��� ���� ��ǰ�� �ǸŸ���Ʈ���� �����, �ǸſϷ� ����Ʈ�� �߰��Ѵ�.
Parameters : Product* soldoutProduct - �ǸŰ� �Ϸ�� ��ǰ
Return Value : void
Created: 2022/5/31 10:24 pm
Author: ����ȣ
*/
void Product::SoldoutProduct(Product* soldoutProduct)
{
    string sellerID = soldoutProduct->GetSellerID();

    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        if (sellerID == get<0>(memberLoginInfo[i]))
        {
            Member* sellerPointer = get<2>(memberLoginInfo[i]);

            vector<Product*> ListSellingProduct = sellerPointer->ListSellingProducts();

            for (int j = 0; j < ListSellingProduct.size(); j++)
            {
                if (ListSellingProduct[j]->GetProductName() == soldoutProduct->GetProductName())
                {
                    ListSellingProduct.erase(ListSellingProduct.begin() + j);

                    sellerPointer->AddSoldoutProduct(soldoutProduct);
                }
            }
        }
    }
}

/*
Function : PurchaseHistory::PurchaseHistory()
Description: ��ǰ ���� ���� ��Ʈ�� Ŭ������ �����ϴ� ������
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
PurchaseHistory::PurchaseHistory()
{
    PurchaseHistoryUI* purchaseHIstoryUI = new PurchaseHistoryUI;
    purchaseHIstoryUI->PushPurchaseHistoryButton(this);
}

/*
Function : PurchaseHistoryUI::PushPurchaseHistoryButton()
Description: ȸ���� ���� ���� ��ȸ ��ư�� ������ ���� ������ �Լ�
Parameters : PurchaseHistory* purchaseHistory
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseHistoryUI::PushPurchaseHistoryButton(PurchaseHistory* purchaseHistory)
{
    purchaseHistory->ShowPurchaseHistory();
}

/*
Function : PurchaseHistoryUI::ShowPurchaseHistories()
Description: ���� ������ ������ִ� �Լ�
Parameters : string sellerID - �Ǹ���ID
             string productName - ��ǰ�̸�
             string madeCompanyName - ������
             int productPrice - ��ǰ����
             int productRemainCount - ��ǰ�����Ȳ
             double averageRating - ��ձ��Ÿ�����
Return Value : void
Created: 2022/5/31 10:24 pm
Author: ����ȣ
*/
void PurchaseHistoryUI::ShowPurchaseHistories(string sellerID, string productName, string madeCompanyName, int productPrice, int productRemainCount, double averageRating)
{
    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << " ";
    outputFile << madeCompanyName << " ";
    outputFile << productPrice << " ";
    outputFile << productRemainCount << " ";
    outputFile << averageRating;
    outputFile << endl;
}
/*
Function : PurchaseHistory::ShowPurchaseHistory()
Description: ���ų����� ����ϴ� �Լ�
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseHistory::ShowPurchaseHistory()
{
    vector <Product*> purchasedProduct = curLoginMember->ListPurchasedProduct();

    vector < tuple<string, string, string, int, int, double> > v;

    for (int i = 0; i < purchasedProduct.size(); i++)
    {
        string sellerID = purchasedProduct[i]->GetSellerID();
        string productName = purchasedProduct[i]->GetProductName();
        string madeCompanyName = purchasedProduct[i]->GetMadeCompanyName();
        int productPrice = purchasedProduct[i]->GetPrice();
        int productRemainCount = purchasedProduct[i]->GetRemainCount();
        double averageRating = purchasedProduct[i]->GetAverageRating();
        v.push_back({ sellerID, productName, madeCompanyName, productPrice, productRemainCount, averageRating });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        PurchaseHistoryUI* purchaseHistoryUI = new PurchaseHistoryUI;
        purchaseHistoryUI->ShowPurchaseHistories(get<0>(v[i]), get<1>(v[i]), get<2>(v[i]), get<3>(v[i]), get<4>(v[i]), get<5>(v[i]));
    }
}

/*
Function : Member::ListPurchasedProduct()
Description: ȸ���� ������ ��ǰ ����Ʈ�� ��ȯ�ϴ� �Լ�
Parameters : ����
Return Value : vector <Product*> purchasedProductListPointer
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
vector <Product*> Member::ListPurchasedProduct()
{
    return this->purchasedProductListPointer;
}

/*
Function : RatingManagement::RatingManagement()
Description: ���� ������ �Է� ��Ʈ�� Ŭ������ �����ϴ� ������
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
RatingManagement::RatingManagement()
{
    RatingUI* ratingUI = new RatingUI;

    ratingUI->SelectPurchasedProduct(this);
    ratingUI->ActivateRatingButton();
    ratingUI->PushRatingButton(this);
    ratingUI->ShowRatingInputWindow();
    ratingUI->CreateNewRating(this);
}

/*
Function : RatingUI::SelectPurchasedProduct()
Description: ������ ��ǰ �߿��� �ϳ��� �����ϴ� ���� ������ �Լ�
Parameters : RatingManagement* ratingManagement
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingUI::SelectPurchasedProduct(RatingManagement* ratingManagement)
{
    ratingManagement->SendPurchasedProduct();
}

/*
Function : RatingManagement::SendPurchasedProduct()
Description: ��ǰ�� �����ϴ� ���� �����ϴ� �Լ� (�ؽ�Ʈ�̱� ������ ����� ����)
Parameters : Product* selectedProduct
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingManagement::SendPurchasedProduct()
{

}

/*
Function : RatingUI::ActivateRatingButton()
Description: ������ ��ǰ�� ���� ������ �Է� ��ư�� Ȱ��ȭ�ϴ� �Լ� (�� ���������� �ؽ�Ʈ���� �ƹ� ����� ����.)
Parameters : ����
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingUI::ActivateRatingButton()
{

}

/*
Function : RatingUI::PushRatingButton()
Description: ���� ������ �Է��� ������ ���� ������ �Լ�
Parameters : RatingManagement* ratingManagement
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingUI::PushRatingButton(RatingManagement* ratingManagement)
{
    ratingManagement->SendRatingButton();
}

/*
Function : RatingManagement::SendRatingButton()
Description: ��ư�� �����ٸ� ���������� �ؽ�Ʈ������ �ƹ��͵� �������� �ʴ´�.
Parameters : ����
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingManagement::SendRatingButton()
{

}

/*
Function : RatingUI::ShowRatingInputWindow()
Description: ���� �Է�â�� ������� �ؽ�Ʈ�� �̹� ���������� ����� ����.
Parameters : ����
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingUI::ShowRatingInputWindow()
{

}

/*
Function : RatingUI::CreateNewRating()
Description: ���� ������ �Է� â���� ���� �������� �߰��ϴ� �Լ�
Parameters : RatingManagement* ratingManagement
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingUI::CreateNewRating(RatingManagement* ratingManagement)
{
    string productName;
    int ratingValue;

    inputFile >> productName >> ratingValue;

    ratingManagement->SendRating(productName, ratingValue);
}

/*
Function : RatingUI::ShowRatingInfo()
Description: ���Ÿ������� ������ִ� �Լ��̴�.
Parameters : string sellerID - �Ǹ���ID
             string productName - ��ǰ�̸�
             int ratingValue - ���Ÿ�����
Return Value : void
Created: 2022/5/31 11:20 pm
Author: ����ȣ
*/
void RatingUI::ShowRatingInfo(string sellerID, string productName, int ratingValue)
{
    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << " ";
    outputFile << ratingValue << endl;
}

/*
Function : RatingManagement::SendRating()
Description: �Է��� ���� �������� �����ϴ� �Լ�
Parameters : int ratingValue
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingManagement::SendRating(string productName, int ratingValue)
{
    vector<Product*> purchasedList = curLoginMember->ListPurchasedProduct();

    for (int i = 0; i < purchasedList.size(); i++)
    {
        if (productName == purchasedList[i]->GetProductName())
        {
            purchasedList[i]->RequestEnrollRating(ratingValue);

            RatingUI *ratingUI = new RatingUI;
            ratingUI->ShowRatingInfo(purchasedList[i]->GetSellerID(), productName, ratingValue);
        }
    }
}

/*
Function : Product::requestEnrollRating()
Description: ��ǰ Ŭ������ ���� ����� ��û�ϴ� �Լ�
Parameters : int ratingValue
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void Product::RequestEnrollRating(int ratingValue)
{
    Rating* rating = new Rating;

    rating->NewRating(ratingValue, this->GetProductName(), curLoginMember->GetMemberName());
}

/*
Function : Rating::newRating()
Description: �ش� ��ǰ�� ���� �������� ����ϴ� �Լ�
Parameters : int ratingValue, string productName, string writer
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void Rating::NewRating(int ratingValue, string productName, string writer)
{
    this->ratingValue = ratingValue;
    this->productName = productName;
    this->writer = writer;

    string sellerID;

    vector <Product*> purchasedList = curLoginMember->ListPurchasedProduct();

    for (int i = 0; i < purchasedList.size(); i++)
    {
        if (productName == purchasedList[i]->GetProductName())
        {
            purchasedList[i]->AddRating(this);
            sellerID = purchasedList[i]->GetSellerID();
            break;
        }
    }
}

/*
Function : Product::ListRating()
Description: �ش� ��ǰ�� ���� ������ ����Ʈ�� ��ȯ�ϴ� �Լ�
Parameters : ����
Return Value : vector <Rating*> ratingListPointer
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
vector <Rating*> Product::ListRating()
{
    return this->ratingListPointer;
}

/*
Function : void doTask()
Description: �� �Լ��� �Է¹��� �޴��� ���� �ش� �޴��� �۾��� �ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/25 : 3:00 pm
Author: �迵��, ����ȣ, ���ؼ�
*/
void doTask() {
    if (inputFile.is_open())    //������ �����ִ��� Ȯ��
    {
        while (!inputFile.eof())    //������ ������ �д°��� �ݺ�
        {
            string str;

            while (1)
            {
                int menu1, menu2;
                inputFile >> menu1 >> menu2;    // ���Ϸκ��� �޴�2�� �� �Է¹���

                if (menu1 == 1 && menu2 == 1)
                {
                    outputFile << "1.1. ȸ������" << endl;

                    if (!loginState)
                    {
                        SignUp* signUp = new SignUp;
                    }

                    outputFile << endl;
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile << "1.2. ȸ��Ż��" << endl;

                    DeleteMyAccount* deleteMyAccount = new DeleteMyAccount;

                    outputFile << endl;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile << "2.1. �α���" << endl;

                    if (!loginState)  // �α��� ���¿����� �α����� �� �� ����.
                    {
                        Login* login = new Login;
                    }
                    
                    outputFile << endl;
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile << "2.2. �α׾ƿ�" << endl;

                    Logout* logout = new Logout;

                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile << "3.1. �Ǹ� �Ƿ� ���" << endl;

                    AddProduct* addProduct = new AddProduct;

                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile << "3.2. ��� ��ǰ ��ȸ" << endl;

                    ViewProduct* viewProduct = new ViewProduct;

                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 3)
                {
                    outputFile << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;

                    ViewSoldoutProduct* viewSoldoutProduct = new ViewSoldoutProduct;

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile << "4.1. ��ǰ ���� �˻�" << endl;

                    SearchProduct* searchProduct = new SearchProduct;

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile << "4.2. ��ǰ ����" << endl;

                    PurchaseProduct* purchaseProduct = new PurchaseProduct;

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile << "4.3. ��ǰ ���� ���� ��ȸ" << endl;

                    PurchaseHistory* purchaseHistory = new PurchaseHistory;

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile << "4.4. ��ǰ ���Ÿ����� ��" << endl;

                    RatingManagement* ratingManagement = new RatingManagement;

                    outputFile << endl;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile << "5.1. �Ǹ� ��ǰ ���" << endl;

                    ProductSalesStats* productSalesStats = new ProductSalesStats;

                    outputFile << endl;
                }
                else if (menu1 == 6 && menu2 == 1)
                {
                    outputFile << "6.1. ����" << endl;
                    return; //doTask �Լ�����
                }
                else
                {
                    getline(inputFile, str);
                }
            }
        }
    }
}

/*
Function : main()
Description: �Ƿ� �Ǹ� ����Ʈ ����, inputFile�� ������ �Է¹޾� outputFile�� ���� ���
Parameters : ����
Return Value : ��������
Created: 2022/5/29 9:00 pm
Author: ���ؼ�
*/
int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}