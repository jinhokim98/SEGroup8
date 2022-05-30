#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile (INPUT_FILE_NAME);   // input.txt �� �б���� ����
ofstream outputFile (OUTPUT_FILE_NAME); // output.txt �� ������� ����

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
    void PushSignUpButton(SignUp *signUp);
    void ShowEssentialInfoInputInterface();
    void InputEssentialInfo(SignUp *signUp);
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
    void DeleteAccountButton(DeleteMyAccount *deleteMyAccount);
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
    void PushLogoutButton(Logout *logout);
    void ShowCompleteLogoutMessage();
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
    Product* selectedProduct;   // ������ ��ǰ �� ���� ���� ��ǰ

public:
    RatingManagement();
    Product* getSelectedProduct() { return selectedProduct; }   // ������ ��ǰ ��ȯ
    void SendPurchasedProduct(Product* selectedProduct);
    void SendRatingButton();
    void SendRating(int ratingValue);
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
    Rating();
    void newRating (int ratingValue, Product* selectedProduct, string writer);
    int getRating();
};

/*
Class: Product
Description: ��ǰ ������ �����ϴ� entity Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class Product
{
private:
    string sellerID;            // �Ǹ���ID
    string productName;         // ��ǰ��
    string madeCompanyName;     // ����ȸ���
    int price;                  // ����
    int remainCount;            // ���� ����
    int productCount;           // ��ǰ ���
    int sellingCount;           // �Ǹ� ����

    vector <Rating*> ratingListPointer;  // ��������Ʈ ������

public:
    Product(string productName, string madeCompanyName, int price, int remainCount);
    string getSellerID() { return sellerID; }   // �Ǹ���ID ��ȯ
    string getProductName() { return productName; } // ��ǰ�� ��ȯ
    string getMadeCompanyName() { return madeCompanyName; } // ����ȸ�� ��ȯ
    int getPrice() { return price; }                // ���� ��ȯ
    int getRemainCount() { return remainCount; }    // ���� ���� ��ȯ
    int getProductCount() { return productCount; }  // ��ǰ ��� ��ȯ
    int getSellingCount() { return sellingCount; }  // �Ǹ� ���� ��ȯ

    vector <Rating*> ListRating();

    bool CheckSelectedProduct(string productName);
    
    bool orderProduct();
    void requestEnrollRating(int rating);
    void createProduct();
    int getSum();
    int getAverageRating();
};

/*
Class: Member
Description: ȸ�� ������ �����ϴ� entity Ŭ����
Created: 2022/5/29 5:00 pm
Author: ����ȣ
mail: rlawlsgh1227@gmail.com
*/
class Member
{
private:
    string id, pw, memberName, idCardNumber;
    vector <Product*> purchasedProductListPointer;
    vector <Product*> sellingProductListPointer;
    vector <Product*> soldoutProductListPointer;
    vector <Product*> allSalesProductListPointer;

public:
    string getID() { return id; }  // ��ü�� id�� get�ϴ� �Լ�
    string getPW() { return pw; }  // ��ü�� pw�� get�ϴ� �Լ�
    string getMemberName() { return memberName; }  // ��ü�� �̸��� get�ϴ� �Լ�
    string getIDCardNumber() { return idCardNumber; }  // ��ü�� �ֹι�ȣ�� get�ϴ� �Լ�
    Member* address_of_object() { return this; }   // �� ��ü�� �ּҸ� get�ϴ� �Լ�
    int checkIDPW(string input_id, string input_pw);
    
    void AddPurchaseProduct(Product* product);
    vector <Product*> ListPurchasedProduct();
    vector <Product* > ListSellingProducts();


    Member();
    Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //������
    ~Member(); //�ı���
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //������ ù���� id , �ι�° ���� pw , ����° ���� �ش簳ü�� ������ ����
Member* curLoginMember; // ���� �α������� ȸ���� ������ �������� ����
bool loginState = false; // ���� �α������̸� true �α׾ƿ����̸� false ������ �������� ����

Product* curSearchedProduct;  // ���� �˻��� ��ǰ�� �������� ����

Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
{
	id = input_id;
	pw = input_pw;
	memberName = input_memberName;
	idCardNumber = input_idCardNumber;

    MemberLoginInfo.push_back({this->getID(), this->getPW(), this->address_of_object()});
}

Member::~Member()
{
    for(int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);
        string pw = get<1>(MemberLoginInfo[i]);
        Member *pointer_Of_Address = get<2>(MemberLoginInfo[i]);
        // MemberLoginInfo ���Ϳ� ����ִ� �� ��ü�� id, pw, �ּ� ������


        string id_Of_CurObject = this->getID(); // ���� ����� ��ü�� id
        string pw_Of_CurObject = this->getPW(); // ���� ����� ��ü�� pw
        Member *pointer_Of_CurObject = this->address_of_object(); // ���� ����� ��ü�� �ּ� ������

        if(id_Of_CurObject == id && pw_Of_CurObject == pw && pointer_Of_CurObject == pointer_Of_Address) // ���� ����� �������ִ� ������ MemberLoginInfo�κ��� �����.
        {
            MemberLoginInfo.erase(MemberLoginInfo.begin() + i);
            break;
        }
    }
}

bool LoginUI::inputIDPW(Login* login)
{
    string input_id, input_pw;
    inputFile>>input_id>>input_pw;    // UI�� id, pw �Է�

    return login->IDPWinputed(input_id,input_pw);   //��Ʈ�� Ŭ�������� �Է��� id, pw ����
}

void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
{
    //�α����� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α����� ȸ���� ���̵� ��й�ȣ�� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curLoginMemberID<<" "<<curLoginMemberPW<<endl<<endl;
}

Login::Login()
{   
    LoginUI *loginUI = new LoginUI;

    if(loginUI->inputIDPW(this))   // id pw�� �Է��Ѵ�. �α����� �����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �´°��) �α��� �Ѵ�.
    {
        loginState=true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->getID(), curLoginMember->getPW());
    }
    else    // �α����� �Ұ����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �ƴѰ��) �α��� ���� ���ϰ� �Ѵ�.
    {
        outputFile<<"ȸ�� ������ ���ų� id�� pw�� ��Ī�� �����ʽ��ϴ�. �α��� ����"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

bool Login::IDPWinputed(string input_id, string input_pw)
{
    if(curLoginMember->checkIDPW(input_id,input_pw)!=-1) // id�� pw�� ��Ī�Ǹ�
    {
        curLoginMember=get<2>(MemberLoginInfo[curLoginMember->checkIDPW(input_id, input_pw)]); // ��Ī�� id,pw�� ȸ������ ���� �α������� ȸ���� ������ ������
        return true;    // �α��� �����ϹǷ� true ��ȯ
    }
    return false;   // �α��� �Ұ����ϸ� false ��ȯ
}

int Member::checkIDPW(string input_id,string input_pw)
{
    for(int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);
        string pw=get<1>(MemberLoginInfo[i]);
        if(id == input_id && pw == input_pw) // �Է��� id�� pw�� ��Ī �Ǹ�
        {
            return i; // �ε��� ��ȯ
        }
    }
    return -1; // ��Ī�� �Ǵ°��� ������ -1��ȯ
}

void LogoutUI::PushLogoutButton(Logout *logout)
{
    if(loginState)  // �α��� ���¿����� �α׾ƿ� �� �� �ִ�.
    {
        logout->DoLogout();
    }
    else
    {
        outputFile<<"�α��� ���¿��� �α׾ƿ� ���ּ���"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
        return;
    }
}

void LogoutUI::ShowCompleteLogoutMessage()
{
    //�α׾ƿ��� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α׾ƿ��� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curLoginMember->getID()<<endl<<endl;
}

Logout::Logout()
{
    LogoutUI *logoutUI = new LogoutUI(); logoutUI->PushLogoutButton(this);
}

void Logout::DoLogout()
{
    LogoutUI *logoutUI = new LogoutUI;
    logoutUI->ShowCompleteLogoutMessage();
    curLoginMember=NULL;
    loginState=false;
}

void SignUpUI::PushSignUpButton(SignUp *signUp)
{
    signUp->ProceedSignUp();
}

void SignUpUI::InputEssentialInfo(SignUp *signUp)
{
    string input_id, input_pw, input_memberName, input_idCardNumber;
    inputFile>>input_memberName>>input_idCardNumber>>input_id>>input_pw;  // ȸ���� �⺻�����Է�

    signUp->getEssentailInfo(input_memberName, input_idCardNumber, input_id, input_pw); // ȸ���� �⺻ ������ ��Ʈ�� Ŭ������ �ѱ�
}

void SignUpUI::ShowEssentialInfoInputInterface()
{
    /*
    ȸ���� �⺻������ �Է��ϴ� â���� �̵��ϴ� �ڵ� ����(�̹����������� �ؽ�Ʈ�� ǥ�� �ϹǷ� �ڵ� ����)
    */
}

void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
{
    // ȸ������ �Ϸ��ߴٴ� �޼��� ���� ���Ŀ� �°� ���
    outputFile<<"> "<<memberName<<" "<<memberIDCardNumber<<" "<<memberID<<" "<<memberPW<<endl<<endl;
}

SignUp::SignUp()
{
    SignUpUI *signUpUI = new SignUpUI;
    signUpUI->PushSignUpButton(this);
    signUpUI->InputEssentialInfo(this);
}

void SignUp::ProceedSignUp()
{
    SignUpUI *signUpUI = new SignUpUI;
    signUpUI->ShowEssentialInfoInputInterface();
}

void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
{
    bool signupPossible = true; //ȸ������ �����ϸ� true �ƴϸ� false

    for(int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);

        if(id==input_id)    // ���Ϳ� �Է��� id�� �����ϸ� id �ߺ��� �ȵǹǷ�
        {
            signupPossible = false; // ������ �Ұ����ϴ�.
        }
    }
    
    if(signupPossible)  // ȸ�������� �����ϸ� (=��ġ�� ���̵������) ȸ�������Ѵ�.
    {
        Member* m = new Member(input_id, input_pw, input_memberName, input_idCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(input_memberName, input_idCardNumber, input_id, input_pw);
    }
    else // ȸ�������� �Ұ����ϸ� (=��ġ�� ���̵�������) ȸ������ ���ϰ��Ѵ�.
    {
        outputFile<<"���̵� ���ļ� ȸ�������� �Ұ��� �մϴ�"<<endl<<endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
{
    deleteMyAccount->DeleteAccount();
}

void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
{
    //ȸ��Ż�� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� ȸ��Ż���� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curMemberID<<endl<<endl;
}

DeleteMyAccount::DeleteMyAccount()
{
    DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
    deleteMyAccountUI->DeleteAccountButton(this);
}

void DeleteMyAccount::DeleteAccount()
{
    if(loginState)  // ���� �α��� ���϶��� ȸ�� Ż�� �����ϴ�.
    {
        DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
        string curMemberID = curLoginMember->getID();   // Ż���ϴ� ȸ���� ���̵� ����
        curLoginMember->~Member(); // ��ü �����Ѵ�.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI�� ȸ�� Ż�� �Ǿ��ٴ� â�� ����
        curLoginMember=NULL; // ���� �α������� ȸ�� ����.
        loginState=false; // �α׾ƿ����·� �����.
    }
    else    // �α׾ƿ� ���¿��� ȸ��Ż�� �ϴ°��� �ȵȴ�.
    {
        outputFile<<"�α����� ������ �Ŀ� ȸ��Ż�� ���ּ���"<<endl<<endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
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
                outputFile << listSellingProducts[j]->getAverageRating() << endl << endl;

                curSearchedProduct = listSellingProducts[j];  // ���� �˻��� ��ǰ���� ���������� ����
            }
        }
    }
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
    if (this->productName == productName)
        return true;
    else
        return false;
}

/*
Function : Member::ListSellingProducts()
Description: ȸ���� �Ǹ��ϰ� �ִ� ��ǰ�� ����Ʈ�� ��ȯ�ϴ� �Լ�
Parameters : ����
Return Value : vector <Product*> sellingProductListPointer
Created: 2022/5/29 7:00 pm
Author: ����ȣ
*/
vector <Product*> Member::ListSellingProducts()
{
    return this->sellingProductListPointer; // ȸ���� ������ �ִ� �Ǹ����� ��ǰ����Ʈ�� vector <Product*> Ÿ������ �����Ѵ�.
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
        outputFile << "�ش� ��ǰ�� ��� �����ϴ�.";
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
        return true;
    }
    else
        return false;
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

    for (int i = 0; i < purchasedProduct.size(); i++)
    {
        outputFile << "> ";
        outputFile << purchasedProduct[i]->getSellerID() << " ";
        outputFile << purchasedProduct[i]->getProductName() << " ";
        outputFile << purchasedProduct[i]->getMadeCompanyName() << " ";
        outputFile << purchasedProduct[i]->getPrice() << " ";
        outputFile << purchasedProduct[i]->getRemainCount() << " ";
        outputFile << purchasedProduct[i]->getAverageRating() << endl << endl;
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
void RatingUI:: SelectPurchasedProduct(RatingManagement* ratingManagement)
{
    string selectedProduct;
    inputFile >> selectedProduct;

    vector <Product*> purchasedProduct = curLoginMember->ListPurchasedProduct();

    for (int i = 0; i < purchasedProduct.size(); i++)
    {
        if(purchasedProduct[i]->getProductName() == selectedProduct)
            ratingManagement->SendPurchasedProduct(purchasedProduct[i]);
    }
}

/*
Function : RatingManagement::SendPurchasedProduct()
Description: ��ǰ�� �����ϴ� ���� �����ϴ� �Լ�
Parameters : Product* selectedProduct
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingManagement::SendPurchasedProduct(Product* selectedProduct)
{
    this->selectedProduct = selectedProduct;
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
    int ratingValue;

    inputFile >> ratingValue;

    ratingManagement->SendRating(ratingValue);
}

/*
Function : RatingManagement::SendRating()
Description: �Է��� ���� �������� �����ϴ� �Լ�
Parameters : int ratingValue
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void RatingManagement::SendRating(int ratingValue)
{
    Product* selectedProduct = this->getSelectedProduct();

    selectedProduct->requestEnrollRating(ratingValue);
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

    rating->newRating(ratingValue, this, curLoginMember->getMemberName());
}

/*
Function : Rating::newRating()
Description: �ش� ��ǰ�� ���� �������� ����ϴ� �Լ�
Parameters : int ratingValue, Product* selectedProduct, string writer
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ����ȣ
*/
void Rating::newRating (int ratingValue, Product* selectedProduct, string writer)
{
    this->ratingValue = ratingValue;
    this->productName = selectedProduct->getProductName();
    this->writer = writer;

    selectedProduct->ListRating().push_back(this);
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
Function : doTask()
Description: ����� �����ϴ� �Լ� (���Ϸκ��� �Է¹޾Ƽ� �پ��� ��� ����)
Parameters : ����
Return Value : ����
Created: 2022/5/29 9:00 pm
Author: ���ؼ�
*/
void doTask(){
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string str;

            while(1)
            {
                int menu1,menu2;
                inputFile>>menu1>>menu2;

                if(menu1 == 1 && menu2 == 1)
                {
                    outputFile<<"1.1. ȸ������"<<endl;

                    if(loginState)  // ���� �α������̶�� ȸ�������� �� �� ����.
                    {
                        outputFile<<"�α׾ƿ� �� ȸ�������� �������ּ���"<<endl<<endl;    // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else    // �α׾ƿ� ���¿����� ȸ�������� �� �� �ִ�.
                    {
                        SignUp *signUp = new SignUp;
                    }
                }
                else if(menu1 == 1 && menu2 == 2)
                {
                    outputFile<<"1.2. ȸ��Ż��"<<endl;

                    DeleteMyAccount *deleteMyAccount = new DeleteMyAccount;
                }
                else if(menu1 == 2 && menu2 == 1)
                {
                    outputFile<<"2.1. �α���"<<endl;

                    if(loginState)  // �α��� ���¿����� �α����� �� �� ����.
                    {
                        outputFile<<"�α��� �� �������ϴ� �α׾ƿ� �� ������ּ���"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else // �α׾ƿ� ���¿����� �α��� �� �� �ִ�.
                    {
                        Login *login = new Login;
                    }
                }
                else if(menu1 == 2 && menu2 == 2)
                {
                    outputFile<<"2.2. �α׾ƿ�"<<endl;

                    Logout *logout = new Logout;

                }
                else if(menu1 == 3 && menu2 == 1)
                {
                    outputFile<<"3.1. �Ǹ� �Ƿ� ���"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 3 && menu2 == 2)
                {
                    outputFile<<"3.2. ��� ��ǰ ��ȸ"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 3 && menu2 == 3)
                {
                    outputFile<<"3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ"<<endl;
                    /*
                        ������
                    */
                }
                else if(menu1 == 4 && menu2 == 1)
                {
                    outputFile<<"4.1. ��ǰ ���� �˻�"<<endl;
                    
                    SearchProduct* searchProduct = new SearchProduct;
        
                }
                else if(menu1 == 4 && menu2 == 2)
                {
                    outputFile<<"4.2. ��ǰ ����"<<endl;
                    
                    PurchaseProduct* purchaseProduct = new PurchaseProduct;
                }
                else if(menu1 == 4 && menu2 == 3)
                {
                    outputFile<<"4.3. ��ǰ ���� ���� ��ȸ"<<endl;
                    
                    PurchaseHistory* purchaseHistory = new PurchaseHistory;
                }
                else if(menu1 == 4 && menu2 == 4)
                {
                    outputFile<<"4.4. ��ǰ ���Ÿ����� ��"<<endl;
                    
                    RatingManagement* ratingManagement = new RatingManagement;
                }
                else if(menu1 == 5 && menu2 == 1)
                {
                    outputFile<<"5.1. �Ǹ� ��ǰ ���"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 6 && menu2 ==1)
                {
                    outputFile<<"6.1. ����"<<endl;
                    return ; //doTask �Լ�����
                }
                getline(inputFile,str);
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