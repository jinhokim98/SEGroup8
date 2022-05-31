#include <iostream>
#include <algorithm>
#include <string>
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
    void getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw);
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
    bool IDPWinputed(string input_id, string input_pw);
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
    bool inputIDPW(Login* login);
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

class AddProduct
{
private:

public:
    AddProduct();
    void ShowAddUI();
    void SendProductData(string input_productName, string input_madeCompanyName, int input_price, int input_productCount);
};

class AddProductUI
{
private:

public:
    void AddProductButton(AddProduct* addProduct);
    void StartInterface();
    void InputProductData(AddProduct* addProduct);
};

class ViewProduct
{
private:

public:
    ViewProduct();
    void ShowSellingProduct();

};

class ViewProductUI
{
private:

public:
    void ViewSalesProductButton(ViewProduct* viewProduct);

};

class ViewSoldoutProduct
{
private:

public:
    ViewSoldoutProduct();
    void ShowSoldoutProduct();
};

class ViewSoldoutProductUI
{
private:

public:
    void ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct);
};

class ProductSalesStats
{
private:

public:
    ProductSalesStats();
    void ShowSalesStats();
};

class ProductSalesStatsUI
{
private:

public:
    void SalesStatsButton(ProductSalesStats* productSalesStats);
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
    void ProceedPurchaseHistory();
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
    void ShowPurchaseHistory();
    void PushPurchaseHistoryButton(PurchaseHistory* purchaseHistory);
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
    void newRating(int ratingValue, string productName, string writer);
    int getRating() { return ratingValue; }
};

class Product
{
protected:
    string productName, madeCompanyName, sellerID;
    int price, productCount, remainCount, sellingCount;

    vector <Rating*> ratingListPointer;  // ��������Ʈ ������

public:
    Product(string input_productName, string input_madeCompanyName, int input_price, int input_productCount);
    string getSellerID() { return sellerID; }   // �Ǹ���ID ��ȯ 
    string getProductName() { return productName; }
    string getMadeCompanyName() { return madeCompanyName; }
    int getPrice() { return price; }
    int getRemainCount() { return remainCount; }    // ���� ���� ��ȯ
    int getProductCount() { return productCount; }
    int getSellingCount() { return sellingCount; }  // �Ǹ� ���� ��ȯ
    vector <Rating*> ListRating();

    void getSellingProductDetails();
    void AddRating(Rating* newRating);
    int getSum();
    double getAverageRating();
    bool CheckSelectedProduct(string productName);
    void soldOutProduct(Product* soldOutProduct);
    bool orderProduct();
    void requestEnrollRating(int rating);
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
    string id, pw, memberName, idCardNumber;
    vector <Product*> purchasedProductListPointer;  // ������ ��ǰ����Ʈ
    vector <Product*> sellingProductListPointer;    // �Ǹ����� ��ǰ��ü�� �ּҸ� �������ϴ� ����Ʈ��
    vector <Product*> soldoutProductListPointer;    // �ǸſϷ�� ��ǰ��ü�� �ּҸ� ����Ű�� ����Ʈ
    vector <Product*> allsalesProductListPointer;   // �ǸſϷ�, �Ǹ��� ��� ��ǰ ��ü�� �ּҸ� ����Ű�� ����Ʈ

public:
    string getID() { return id; }  // ��ü�� id�� get�ϴ� �Լ�
    string getPW() { return pw; }  // ��ü�� pw�� get�ϴ� �Լ�
    string getMemberName() { return memberName; }  // ��ü�� �̸��� get�ϴ� �Լ�
    string getIDCardNumber() { return idCardNumber; }  // ��ü�� �ֹι�ȣ�� get�ϴ� �Լ�
    Member* address_of_object() { return this; }   // �� ��ü�� �ּҸ� get�ϴ� �Լ�
    int checkIDPW(string input_id, string input_pw); // �Է¹��� id, pw�� ��Ī�Ǵ��� Ȯ���ϴ� �Լ�

    Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //������
    ~Member(); //�ı���

    void AddPurchaseProduct(Product* product);
    void AddNewProduct(string input_productName, string input_madeCompanyName, int input_price, int input_productCount);
    void AddRegistedNewProuduct(Product* newProduct);
    void AddSoldOutProduct(Product* soldoutproduct);
    void AddAllSalesProduct(Product* newProduct);
    vector <Product*> ListPurchasedProduct();
    vector <Product*> ListSellingProducts(); //�Ǹ����� ��ǰ����Ʈ�� ����Ű�� ������
    vector <Product*> ListSoldoutProducts(); //�ǸſϷ�� ��ǰ ����Ʈ�� ����Ű�� ������
    vector <Product*> ListAllsalesProducts(); //�Ǹ����� ��ǰ�� �ǸſϷ�� ��ǰ ��θ� ����Ű�� ������
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //������ ù���� id , �ι�° ���� pw , ����° ���� Member��ü�� �ּҸ�����Ű�� ������ ������ ����
Member* curLoginMember; // ���� �α������� ȸ���� ������ �������� ����
bool loginState = false; // ���� �α������̸� true �α׾ƿ����̸� false ������ �������� ����

Product* curSearchedProduct;  // ���� �˻��� ��ǰ�� �������� ����

Product::Product(string input_productName, string input_madeCompanyName, int input_price, int input_productCount)   // ����2 �𵨸��� �̸��� CreateProduct�� �ش� CreateProduct �̸��� �ٲ� �׳� �����ڷ� ����
{
    sellerID = curLoginMember->getID();
    productName = input_productName;
    madeCompanyName = input_madeCompanyName;
    price = input_price;
    productCount = input_productCount;
    remainCount = productCount; // �����Ǿ������� ���� ���� = ����
    sellingCount = 0;   // �����Ǿ������� �� ���� = 0

    curLoginMember->AddRegistedNewProuduct(this);   // ���� �α��� �� ȸ���� �Ǹ����� ��ǰ�� ����Ʈ�� �߰��Ѵ�
    curLoginMember->AddAllSalesProduct(this);

    outputFile << this->productName << " " << this->madeCompanyName << " " << this->price << " " << this->productCount << endl << endl; // ������ ��ǰ ��ü�� �̸�, ����ȸ���, ���� ,������ ����Ѵ�.
}

void Product::getSellingProductDetails()
{
    outputFile << this->productName << " " << this->madeCompanyName << " " << this->price << " " << this->productCount << endl;
}

int Product::getSum()
{
    int sum = 0;
    int price = this->getPrice();
    int selling_count = this->getSellingCount();

    sum = price * selling_count;
    return sum;
}

double Product::getAverageRating()
{
    double average_rating = 0;
    int sum = 0;
    int count = 0;

    vector <Rating*> listRating;

    listRating = this->ListRating();

    for (int i = 0; i < listRating.size(); i++)
    {
        count++;
        sum += listRating[i]->getRating();
    }

    if (count == 0)
    {
        return 0;
    }
    else
    {
        average_rating = (double)sum / count;
        return average_rating;
    }
}

void Product::AddRating(Rating* newRating)
{
    (this->ratingListPointer).push_back(newRating);
}

/*
Function : Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
Description: �� �Լ��� Member Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
string input_memberName - �Էµ� ȸ���� �̸�
string input_idCardNumber - �Էµ� �ֹι�ȣ
Return Value : ����
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
{
    id = input_id;
    pw = input_pw;
    memberName = input_memberName;
    idCardNumber = input_idCardNumber;

    MemberLoginInfo.push_back({ this->getID(), this->getPW(), this->address_of_object() }); // �Էµ� ȸ���� ������ MemberLoginInfo�� Ǫ���Ѵ�.
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
    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);
        string pw = get<1>(MemberLoginInfo[i]);
        Member* pointer_Of_Address = get<2>(MemberLoginInfo[i]);
        // MemberLoginInfo ���Ϳ� ����ִ� �� ��ü�� id, pw, ��ü�� �ּ� ������


        string id_Of_CurObject = this->getID(); // ���� ����� ��ü�� id
        string pw_Of_CurObject = this->getPW(); // ���� ����� ��ü�� pw
        Member* pointer_Of_CurObject = this->address_of_object(); // ���� ����� ��ü�� �ּ� ������

        if (id_Of_CurObject == id && pw_Of_CurObject == pw && pointer_Of_CurObject == pointer_Of_Address) // ���� ����� �������ִ� ������ MemberLoginInfo�κ��� �����.
        {
            MemberLoginInfo.erase(MemberLoginInfo.begin() + i);
            break;
        }
    }
}

void Member::AddNewProduct(string input_productName, string input_madeCompanyName, int input_price, int input_productCount)
{
    Product* newProduct = new Product(input_productName, input_madeCompanyName, input_price, input_productCount); // ���� ������ ��ǰ ��ü�� �����Ѵ�
}

void Member::AddRegistedNewProuduct(Product* newProduct)
{
    sellingProductListPointer.push_back(newProduct);
}

void Member::AddSoldOutProduct(Product* soldoutproduct)
{
    (this->soldoutProductListPointer).push_back(soldoutproduct);
}

void Member::AddAllSalesProduct(Product* newProduct)
{
    allsalesProductListPointer.push_back(newProduct);
}

vector <Product*> Member::ListSellingProducts()
{
    return this->sellingProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

vector <Product*> Member::ListSoldoutProducts()
{
    return this->soldoutProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

vector <Product*> Member::ListAllsalesProducts()
{
    return this->allsalesProductListPointer; // ���� Ÿ���� vector <Product*> Ÿ���̴�
}

/*
Function : bool LoginUI::inputIDPW(Login* login)
Description: �� �Լ��� �α��ν� id�� pw�� �Է��ϴ� �Լ��Դϴ�.
Parameters : Login* login - �α��� Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool LoginUI::inputIDPW(Login* login)
{
    string input_id, input_pw;
    inputFile >> input_id >> input_pw;    // UI�� id, pw �Է�

    return login->IDPWinputed(input_id, input_pw);   //��Ʈ�� Ŭ�������� �Է��� id, pw ����
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
    outputFile << "> " << curLoginMemberID << " " << curLoginMemberPW << endl << endl;
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

    if (loginUI->inputIDPW(this))   // id pw�� �Է��Ѵ�. �α����� �����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �´°��) �α��� �Ѵ�.
    {
        loginState = true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->getID(), curLoginMember->getPW());
    }
    else    // �α����� �Ұ����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �ƴѰ��) �α��� ���� ���ϰ� �Ѵ�.
    {
        outputFile << "ȸ�� ������ ���ų� id�� pw�� ��Ī�� �����ʽ��ϴ�. �α��� ����" << endl << endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

/*
Function : bool Login::IDPWinputed(string input_id, string input_pw)
Description: �� �Լ��� UI�κ��� �Է¹��� id, pw�� ��Ʈ�� Ŭ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool Login::IDPWinputed(string input_id, string input_pw)
{
    if (curLoginMember->checkIDPW(input_id, input_pw) != -1) // id�� pw�� ��Ī�Ǹ�
    {
        curLoginMember = get<2>(MemberLoginInfo[curLoginMember->checkIDPW(input_id, input_pw)]); // ��Ī�� id,pw�� ȸ������ ���� �α������� ȸ���� ������ ������
        return true;    // �α��� �����ϹǷ� true ��ȯ
    }
    return false;   // �α��� �Ұ����ϸ� false ��ȯ
}

/*
Function : int Member::checkIDPW(string input_id,string input_pw)
Description: �� �Լ��� �α����Ҷ� �Է¹��� id�� pw�� ���� ��Ī�� �Ǵ��� Ȯ���ϴ� �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
Return Value : int
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
int Member::checkIDPW(string input_id, string input_pw)
{
    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);
        string pw = get<1>(MemberLoginInfo[i]);
        if (id == input_id && pw == input_pw) // �Է��� id�� pw�� ��Ī �Ǹ�
        {
            return i; // �ε��� ��ȯ
        }
    }
    return -1; // ��Ī�� �Ǵ°��� ������ -1��ȯ
}

/*
Function : LogoutUI::PushLogoutButton(Logout *logout)
Description: �� �Լ��� �α׾ƿ� ��ư�� ������ �α׾ƿ��� �����ϴ� �Լ��Դϴ�.
Parameters : Logout *logout - Logout ��ü�� �ּҸ� ����Ű�� ������
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
    else
    {
        outputFile << "�α��� ���¿��� �α׾ƿ� ���ּ���" << endl << endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
        return;
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
    outputFile << "> " << curLoginMember->getID() << endl << endl;
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
Function : void SignUpUI::PushSignUpButton(SignUp *signUp)
Description: �� �Լ��� ȸ������ ��ư ������ ȸ�������� �����ϴ� �Լ��Դϴ�.
Parameters : SignUp *signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::PushSignUpButton(SignUp* signUp)
{
    signUp->ProceedSignUp();
}

/*
Function : void SignUpUI::InputEssentialInfo(SignUp *signUp)
Description: �� �Լ��� ȸ���� �⺻����(id, pw, ȸ���̸�, ȸ���ֹι�ȣ)�� �Է��ϴ� �Լ��Դϴ�.
Parameters : SignUp *signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::InputEssentialInfo(SignUp* signUp)
{
    string input_id, input_pw, input_memberName, input_idCardNumber;
    inputFile >> input_memberName >> input_idCardNumber >> input_id >> input_pw;  // ȸ���� �⺻�����Է�

    signUp->getEssentailInfo(input_memberName, input_idCardNumber, input_id, input_pw); // ȸ���� �⺻ ������ ��Ʈ�� Ŭ������ �ѱ�
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
    outputFile << "> " << memberName << " " << memberIDCardNumber << " " << memberID << " " << memberPW << endl << endl;
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
Function : void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
Description: �� �Լ��� �Է¹��� ȸ�����̸�, �ֹι�ȣ, �Էµ� id, �Էµ� pw ������ get�Ͽ� ȸ������ �۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string input_memberName - �Է¹��� ȸ���� �̸�
string input_idCardNumber - �Է¹��� ȸ���� �ֹι�ȣ
string input_id - �Է¹��� ȸ���� id
string input_pw - �Է¹��� ȸ���� pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
{
    bool signupPossible = true; //ȸ������ �����ϸ� true �ƴϸ� false

    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);

        if (id == input_id)    // ���Ϳ� �Է��� id�� �����ϸ� id �ߺ��� �ȵǹǷ�
        {
            signupPossible = false; // ������ �Ұ����ϴ�.
        }
    }

    if (signupPossible)  // ȸ�������� �����ϸ� (=��ġ�� ���̵������) ȸ�������Ѵ�.
    {
        Member* m = new Member(input_id, input_pw, input_memberName, input_idCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(input_memberName, input_idCardNumber, input_id, input_pw);
    }
    else // ȸ�������� �Ұ����ϸ� (=��ġ�� ���̵�������) ȸ������ ���ϰ��Ѵ�.
    {
        outputFile << "���̵� ���ļ� ȸ�������� �Ұ��� �մϴ�" << endl << endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

/*
Function : void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
Description: �� �Լ��� ȸ��Ż�� ��ư�� ������ ȸ��Ż�� �����ϴ� �Լ��Դϴ�.
Parameters : DeleteMyAccount *deleteMyAccount - DeleteMyAccount Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
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
    outputFile << "> " << curMemberID << endl << endl;
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
Function : DeleteMyAccount::DeleteAccount()
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
        string curMemberID = curLoginMember->getID();   // Ż���ϴ� ȸ���� ���̵� ����
        curLoginMember->~Member(); // ��ü �����Ѵ�.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI�� ȸ�� Ż�� �Ǿ��ٴ� â�� ����
        curLoginMember = NULL; // ���� �α������� ȸ�� ����.
        loginState = false; // �α׾ƿ����·� �����.
    }
    else    // �α׾ƿ� ���¿��� ȸ��Ż�� �ϴ°��� �ȵȴ�.
    {
        outputFile << "�α����� ������ �Ŀ� ȸ��Ż�� ���ּ���" << endl << endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

AddProduct::AddProduct()
{
    if (loginState)  // �α��� �� ���� �� ���� �Ǹ� �Ƿ��� ��� �� ���ִ�.
    {
        AddProductUI* addProductUI = new AddProductUI;
        addProductUI->AddProductButton(this);
        addProductUI->InputProductData(this);
    }
    else
    {
        outputFile << "�α��� ���¿��� �Ƿ� ����� �� �� �ֽ��ϴ�. �α��� ���ּ���" << endl << endl;
    }
}

void AddProduct::ShowAddUI()
{
    AddProductUI* addProductUI = new AddProductUI;
    addProductUI->StartInterface();
}

void AddProduct::SendProductData(string input_productName, string input_madeCompanyName, int input_price, int input_productCount)
{
    curLoginMember->AddNewProduct(input_productName, input_madeCompanyName, input_price, input_productCount);   // ���� �α��� �� ȸ���� �� ��ǰ�� ����ϴ� �Լ��� ȣ���Ѵ�
}

void AddProductUI::AddProductButton(AddProduct* addProduct)
{
    addProduct->ShowAddUI();
}

void AddProductUI::StartInterface()
{
    /*
    ��ǰ�� ������ �Է��ϴ� â���� �̵��ϴ� �ڵ� ����(�̹����������� �ؽ�Ʈ�� ǥ�� �ϹǷ� �ڵ� ����)
    */
}

void AddProductUI::InputProductData(AddProduct* addProduct)
{
    string input_productName, input_madeCompanyName;
    int input_price, input_productCount;

    inputFile >> input_productName >> input_madeCompanyName >> input_price >> input_productCount;   // ��ǰ��, ����ȸ���, ����, ������ ���Ϸ� ���� �Է¹޴´�.

    addProduct->SendProductData(input_productName, input_madeCompanyName, input_price, input_productCount); // �Է¹��� ������ ��Ʈ�� Ŭ������ �����ش�.
}

ViewProduct::ViewProduct()
{
    if (loginState)  // �α��� ���¿����� �Ǹ����� �Ƿ��� ��ȸ �����ϴ�.
    {
        ViewProductUI* viewProductUI = new ViewProductUI;

        viewProductUI->ViewSalesProductButton(this);
    }
    else    // ��α��� ���¿����� �翬�� �Ǹ����� �Ƿ��� ��ȸ �Ұ����ϴ�.
    {
        outputFile << "�α������� ������ �Ǹ����� �Ƿ��� ��ȸ �� �� �����ϴ�. �α������ּ���." << endl << endl;// ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

void ViewProduct::ShowSellingProduct()
{
    vector <Product*> listSellingProducts;
    // listSellingProducts�� ListSellingProducts() �Լ��κ��� ���� �α����� ȸ���� �Ǹ����� ��ǰ�� �ּҵ��� �������ϴ� ����Ʈ�� ��ȯ�ޱ� ���� ������

    listSellingProducts = curLoginMember->ListSellingProducts(); // ����2 �Ǹ��Ƿ� ��ȸ 1.1.1�� �ش�

    for (int i = 0; i < listSellingProducts.size(); i++) // �� ��ǰ�� �ּ��� �����͵��� �޾ƿ����� �ݺ����� ���� �������� ����Ѵ�. ���� 2 �Ǹ��Ƿ� ��ȸ 1.1.2�� �ش�
    {
        outputFile << listSellingProducts[i]->getProductName() << " " << listSellingProducts[i]->getMadeCompanyName() << " " << listSellingProducts[i]->getPrice() << " " << listSellingProducts[i]->getProductCount() << endl;
    }

    outputFile << endl;
}

void ViewProductUI::ViewSalesProductButton(ViewProduct* viewProduct)
{
    viewProduct->ShowSellingProduct();
}

ViewSoldoutProduct::ViewSoldoutProduct()
{
    if (loginState)  // �α��� ���¿����� �ǸſϷ�� �Ƿ��� ��ȸ �����ϴ�.
    {
        ViewSoldoutProductUI* viewSoldoutProductUI = new ViewSoldoutProductUI;

        viewSoldoutProductUI->ViewSoldoutProductButton(this);
    }
    else    // ��α��� ���¿����� �Ǹ� �Ϸ�� �Ƿ��� ��ȸ �Ұ����ϴ�. ����ó��
    {
        outputFile << "�α������� ������ �ǸſϷ�� �Ƿ��� ��ȸ �� �� �����ϴ�. �α������ּ���." << endl << endl;// ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

void ViewSoldoutProductUI::ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct)
{
    viewSoldoutProduct->ShowSoldoutProduct();
}

void ViewSoldoutProduct::ShowSoldoutProduct()
{
    vector <Product*> listSoldoutProducts;

    listSoldoutProducts = curLoginMember->ListSoldoutProducts();

    for (int i = 0; i < listSoldoutProducts.size(); i++) // �� ��ǰ�� �ּ��� �����͵��� �޾ƿ����� �ݺ����� ���� �������� ����Ѵ�. ���� 2 �Ǹ��Ƿ� ��ȸ 1.1.2�� �ش�
    {
        outputFile << "> " << listSoldoutProducts[i]->getProductName() << " " << listSoldoutProducts[i]->getMadeCompanyName() << " " << listSoldoutProducts[i]->getPrice() << " " << listSoldoutProducts[i]->getProductCount() << endl;
    }
    outputFile << endl;
}


ProductSalesStats::ProductSalesStats()
{
    if (loginState) //�α��� ���� Ȯ��
    {
        ProductSalesStatsUI* productSalesStats = new ProductSalesStatsUI;

        productSalesStats->SalesStatsButton(this);
    }
    else //�α��� ���� �ʾҴٸ� �Ǹ����� ����� �� ����.
    {
        outputFile << "�α������� ������ ��ǰ�Ǹ���踦 ��ȸ �� �� �����ϴ�. �α������ּ���." << endl << endl;// ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

void ProductSalesStatsUI::SalesStatsButton(ProductSalesStats* productSalesStats)
{
    productSalesStats->ShowSalesStats();
}

void ProductSalesStats::ShowSalesStats()
{
    if (loginState)
    {

        vector <Product*> listAllSalesProduct;
        listAllSalesProduct = curLoginMember->ListAllsalesProducts(); //���� �α��ε� ȸ���� ��� ��ǰ ����Ʈ�� �����´�.

        for (int i = 0; i < listAllSalesProduct.size(); i++)
        {
            outputFile << listAllSalesProduct[i]->getProductName() << " ";
            outputFile << listAllSalesProduct[i]->getSum() << " ";
            outputFile << listAllSalesProduct[i]->getAverageRating() << " ";
            outputFile << endl;
        }
        outputFile << endl;

    }
    else
    {
        outputFile << "�α����� ������ �Ŀ� ��ǰ�Ǹ���踦 �������ּ���" << endl << endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
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

    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        listSellingProducts.clear();    // �� �ݺ����� listSellingProducts ����Ʈ �ʱ�ȭ

        Member* member = get<2>(MemberLoginInfo[i]);    // �ݺ����� ���� ��� �� ȸ������  

        listSellingProducts = member->ListSellingProducts();    // �Ǹ����� ��ǰ�� �ּ� �����͸� �޾ƿ�

        for (int j = 0; j < listSellingProducts.size(); j++)
        {
            if (listSellingProducts[j]->CheckSelectedProduct(productName) == true)
            {
                outputFile << "> ";
                outputFile << listSellingProducts[j]->getSellerID() << " ";
                outputFile << listSellingProducts[j]->getProductName() << " ";
                outputFile << listSellingProducts[j]->getMadeCompanyName() << " ";
                outputFile << listSellingProducts[j]->getPrice() << " ";
                outputFile << listSellingProducts[j]->getRemainCount() << " ";
                outputFile << listSellingProducts[j]->getAverageRating();
                outputFile << endl << endl;

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
    if (this->productName == productName && this->getRemainCount() > 0)
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
Function : PurchaseProduct::ProceedPurchase()
Description: ��Ʈ�� Ŭ������ ��ư ���� �� ����
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseProduct::ProceedPurchase()
{
    if (curSearchedProduct->orderProduct() == true) // �ش� ��ǰ�� �ֹ��Ѵ�.
    {
        curLoginMember->AddPurchaseProduct(curSearchedProduct); // ������ ��ǰ����Ʈ�� �߰�

        outputFile << "> ";
        outputFile << curSearchedProduct->getSellerID() << " ";
        outputFile << curSearchedProduct->getProductName() << endl << endl;

    }
    else
    {
        outputFile << "�ش� ��ǰ�� ��� �����ϴ�." << endl << endl;
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
bool Product::orderProduct()
{
    if (remainCount > 0)
    {
        remainCount--;  // ��ǰ�� �����߱� ������ ��� �ϳ��� ����.

        sellingCount++; //��ǰ�� �����߱� ������ ���ż��� �ϳ� �ø���.

        if (remainCount == 0)
        {
            this->soldOutProduct(this);
        }
        return true;
    }
    else
        return false;
}

void Product::soldOutProduct(Product* soldOutProduct)
{
    string sellerID = soldOutProduct->getSellerID();

    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        if (sellerID == get<0>(MemberLoginInfo[i]))
        {
            Member* sellerPointer = get<2>(MemberLoginInfo[i]);

            vector<Product*> ListSellingProduct = sellerPointer->ListSellingProducts();

            for (int j = 0; j < ListSellingProduct.size(); j++)
            {
                if (ListSellingProduct[j]->getProductName() == soldOutProduct->getProductName())
                {
                    ListSellingProduct.erase(ListSellingProduct.begin() + j);

                    sellerPointer->AddSoldOutProduct(soldOutProduct);
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
    purchaseHistory->ProceedPurchaseHistory();
}

/*
Function : PurchaseHistory::ProceedPurchaseHistory()
Description: ��Ʈ�� Ŭ������ ��ư ���� ���� ����
Parameters : ����
Return Value : ����
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
void PurchaseHistory::ProceedPurchaseHistory()
{
    vector <Product*> purchasedProduct = curLoginMember->ListPurchasedProduct();

    vector < tuple<string, string, string, int, int, double> > v;

    for (int i = 0; i < purchasedProduct.size(); i++)
    {
        string sellerID = purchasedProduct[i]->getSellerID();
        string productName = purchasedProduct[i]->getProductName();
        string madeCompanyName = purchasedProduct[i]->getMadeCompanyName();
        int productPrice = purchasedProduct[i]->getPrice();
        int productRemainCount = purchasedProduct[i]->getRemainCount();
        double averageRating = purchasedProduct[i]->getAverageRating();
        v.push_back({ sellerID, productName, madeCompanyName, productPrice, productRemainCount, averageRating });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        outputFile << "> ";
        outputFile << get<0>(v[i]) << " ";
        outputFile << get<1>(v[i]) << " ";
        outputFile << get<2>(v[i]) << " ";
        outputFile << get<3>(v[i]) << " ";
        outputFile << get<4>(v[i]) << " ";
        outputFile << get<5>(v[i]);
        outputFile << endl;
    }
    outputFile << endl;
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
        if (productName == purchasedList[i]->getProductName())
            purchasedList[i]->requestEnrollRating(ratingValue);
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
void Product::requestEnrollRating(int ratingValue)
{
    Rating* rating = new Rating;

    rating->newRating(ratingValue, this->getProductName(), curLoginMember->getMemberName());
}

/*
Function : Rating::newRating()
Description: �ش� ��ǰ�� ���� �������� ����ϴ� �Լ�
Parameters : int ratingValue, string productName, string writer
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void Rating::newRating(int ratingValue, string productName, string writer)
{
    this->ratingValue = ratingValue;
    this->productName = productName;
    this->writer = writer;

    string sellerID;

    vector <Product*> purchasedList = curLoginMember->ListPurchasedProduct();

    for (int i = 0; i < purchasedList.size(); i++)
    {
        if (productName == purchasedList[i]->getProductName())
        {
            purchasedList[i]->AddRating(this);
            sellerID = purchasedList[i]->getSellerID();
            break;
        }
    }

    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << " ";
    outputFile << ratingValue << endl << endl;
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
Author: ���ؼ�
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

                    if (loginState)  // ���� �α������̶�� ȸ�������� �� �� ����.
                    {
                        outputFile << "�α׾ƿ� �� ȸ�������� �������ּ���" << endl << endl;    // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else    // �α׾ƿ� ���¿����� ȸ�������� �� �� �ִ�.
                    {
                        SignUp* signUp = new SignUp;
                    }
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile << "1.2. ȸ��Ż��" << endl;

                    DeleteMyAccount* deleteMyAccount = new DeleteMyAccount;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile << "2.1. �α���" << endl;

                    if (loginState)  // �α��� ���¿����� �α����� �� �� ����.
                    {
                        outputFile << "�α��� �� �������ϴ� �α׾ƿ� �� ������ּ���" << endl << endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else // �α׾ƿ� ���¿����� �α��� �� �� �ִ�.
                    {
                        Login* login = new Login;
                    }
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile << "2.2. �α׾ƿ�" << endl;

                    Logout* logout = new Logout;

                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile << "3.1. �Ǹ� �Ƿ� ���" << endl;

                    AddProduct* addProduct = new AddProduct;

                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile << "3.2. ��� ��ǰ ��ȸ" << endl;

                    ViewProduct* viewProduct = new ViewProduct;

                }
                else if (menu1 == 3 && menu2 == 3)
                {
                    outputFile << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;

                    ViewSoldoutProduct* viewSoldoutProduct = new ViewSoldoutProduct;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile << "4.1. ��ǰ ���� �˻�" << endl;

                    SearchProduct* searchProduct = new SearchProduct;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile << "4.2. ��ǰ ����" << endl;

                    PurchaseProduct* purchaseProduct = new PurchaseProduct;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile << "4.3. ��ǰ ���� ���� ��ȸ" << endl;

                    PurchaseHistory* purchaseHistory = new PurchaseHistory;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile << "4.4. ��ǰ ���Ÿ����� ��" << endl;

                    RatingManagement* ratingManagement = new RatingManagement;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile << "5.1. �Ǹ� ��ǰ ���" << endl;

                    ProductSalesStats* productSalesStats = new ProductSalesStats;
                }
                else if (menu1 == 6 && menu2 == 1)
                {
                    outputFile << "6.1. ����" << endl;
                    return; //doTask �Լ�����
                }
                getline(inputFile, str);
            }
        }
    }
}

/*
Function : main()
Description: �Ƿ� �Ǹ� ����Ʈ ����, inputFile�� ������ �Է¹޾� outputFile�� ���� ���
Parameters : ����
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ���ؼ�
*/
int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}