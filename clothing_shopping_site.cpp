#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile (INPUT_FILE_NAME);   // input.txt 를 읽기모드로 열음
ofstream outputFile (OUTPUT_FILE_NAME); // output.txt 를 쓰기모드로 얻음

/*
Class: SignUp
Description: 회원가입 컨트롤 클래스이다.
Created: 2022/5/26 6:00 am
Author: 최준수
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
Description: 회원가입 바운더리 클래스이다.
Created: 2022/5/26 6:00 am
Author: 최준수
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
Description: 회원탈퇴 컨트롤 클래스이다.
Created: 2022/5/26 6:00 am
Author: 최준수
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
Description: 회원탈퇴 바운더리 클래스이다.
Created: 2022/5/26 6:00 am
Author: 최준수
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
Description: 로그인 컨트롤 클래스 이다.
Created: 2022/5/26 3:00 am
Author: 최준수
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
Description: 로그인 바운더리 클래스이다.
Created: 2022/5/26 3:00 am
Author: 최준수
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
Description: 로그아웃 컨트롤 클래스이다.
Created: 2022/5/26 3:00 am
Author: 최준수
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
Description: 로그아웃 바운더리 클래스이다.
Created: 2022/5/26 3:00 am
Author: 최준수
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
Description: 상품 정보 검색 컨트롤 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 상품 정보 검색 바운더리 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 상품 구매 컨트롤 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 상품 구매 바운더리 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 구매 내역 조회 컨트롤 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 구매 내역 조회 바운더리 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 만족도 입력 컨트롤 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
mail: rlawlsgh1227@gmail.com
*/
class RatingManagement
{
private:
    Product* selectedProduct;   // 구매한 상품 중 내가 누른 상품

public:
    RatingManagement();
    Product* getSelectedProduct() { return selectedProduct; }   // 선택한 상품 반환
    void SendPurchasedProduct(Product* selectedProduct);
    void SendRatingButton();
    void SendRating(int ratingValue);
};

/*
Class: RatingUI
Description: 만족도 입력 바운더리 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
Description: 평점을 저장하는 entity 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
mail: rlawlsgh1227@gmail.com
*/
class Rating
{
private:
    int ratingValue;    // 평점
    string productName; // 상품 이름
    string writer;      // 평가한 사람

public:
    Rating();
    void newRating (int ratingValue, Product* selectedProduct, string writer);
    int getRating();
};

/*
Class: Product
Description: 상품 정보를 저장하는 entity 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
mail: rlawlsgh1227@gmail.com
*/
class Product
{
private:
    string sellerID;            // 판매자ID
    string productName;         // 상품명
    string madeCompanyName;     // 제작회사명
    int price;                  // 가격
    int remainCount;            // 남은 수량
    int productCount;           // 상품 재고
    int sellingCount;           // 판매 수량

    vector <Rating*> ratingListPointer;  // 평점리스트 포인터

public:
    Product(string productName, string madeCompanyName, int price, int remainCount);
    string getSellerID() { return sellerID; }   // 판매자ID 반환
    string getProductName() { return productName; } // 상품명 반환
    string getMadeCompanyName() { return madeCompanyName; } // 제작회사 반환
    int getPrice() { return price; }                // 가격 반환
    int getRemainCount() { return remainCount; }    // 남은 수량 반환
    int getProductCount() { return productCount; }  // 상품 재고 반환
    int getSellingCount() { return sellingCount; }  // 판매 수량 반환

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
Description: 회원 정보를 저장하는 entity 클래스
Created: 2022/5/29 5:00 pm
Author: 김진호
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
    string getID() { return id; }  // 개체의 id를 get하는 함수
    string getPW() { return pw; }  // 개체의 pw를 get하는 함수
    string getMemberName() { return memberName; }  // 개체의 이름을 get하는 함수
    string getIDCardNumber() { return idCardNumber; }  // 개체의 주민번호를 get하는 함수
    Member* address_of_object() { return this; }   // 각 개체의 주소를 get하는 함수
    int checkIDPW(string input_id, string input_pw);
    
    void AddPurchaseProduct(Product* product);
    vector <Product*> ListPurchasedProduct();
    vector <Product* > ListSellingProducts();


    Member();
    Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //생성자
    ~Member(); //파괴자
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //벡터의 첫값은 id , 두번째 값은 pw , 세번째 값은 해당개체의 정보를 담음
Member* curLoginMember; // 현재 로그인중인 회원의 정보를 전역으로 설정
bool loginState = false; // 현재 로그인중이면 true 로그아웃중이면 false 정보를 전역으로 설정

Product* curSearchedProduct;  // 현재 검색한 상품을 전역으로 설정

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
        // MemberLoginInfo 벡터에 들어있는 각 개체별 id, pw, 주소 포인터


        string id_Of_CurObject = this->getID(); // 현재 멤버의 객체의 id
        string pw_Of_CurObject = this->getPW(); // 현재 멤버의 객체의 pw
        Member *pointer_Of_CurObject = this->address_of_object(); // 현재 멤버의 객체의 주소 포인터

        if(id_Of_CurObject == id && pw_Of_CurObject == pw && pointer_Of_CurObject == pointer_Of_Address) // 현재 멤버가 가지고있는 정보를 MemberLoginInfo로부터 지운다.
        {
            MemberLoginInfo.erase(MemberLoginInfo.begin() + i);
            break;
        }
    }
}

bool LoginUI::inputIDPW(Login* login)
{
    string input_id, input_pw;
    inputFile>>input_id>>input_pw;    // UI에 id, pw 입력

    return login->IDPWinputed(input_id,input_pw);   //컨트롤 클래스에게 입력한 id, pw 전달
}

void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
{
    //로그인이 완료되었다는 창을 띄우는 코드 (이번과제에서는 로그인한 회원의 아이디 비밀번호를 텍스트로 출력)
    outputFile<<"> "<<curLoginMemberID<<" "<<curLoginMemberPW<<endl<<endl;
}

Login::Login()
{   
    LoginUI *loginUI = new LoginUI;

    if(loginUI->inputIDPW(this))   // id pw를 입력한다. 로그인이 가능하면 (입력한 id와 입력한 pw가 매칭이 맞는경우) 로그인 한다.
    {
        loginState=true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->getID(), curLoginMember->getPW());
    }
    else    // 로그인이 불가능하면 (입력한 id와 입력한 pw가 매칭이 아닌경우) 로그인 하지 못하게 한다.
    {
        outputFile<<"회원 정보가 없거나 id와 pw가 매칭이 되지않습니다. 로그인 실패"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
    }
}

bool Login::IDPWinputed(string input_id, string input_pw)
{
    if(curLoginMember->checkIDPW(input_id,input_pw)!=-1) // id와 pw가 매칭되면
    {
        curLoginMember=get<2>(MemberLoginInfo[curLoginMember->checkIDPW(input_id, input_pw)]); // 매칭된 id,pw의 회원으로 현재 로그인중인 회원의 정보를 설정함
        return true;    // 로그인 가능하므로 true 반환
    }
    return false;   // 로그인 불가능하면 false 반환
}

int Member::checkIDPW(string input_id,string input_pw)
{
    for(int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);
        string pw=get<1>(MemberLoginInfo[i]);
        if(id == input_id && pw == input_pw) // 입력한 id와 pw가 매칭 되면
        {
            return i; // 인덱스 반환
        }
    }
    return -1; // 매칭이 되는것이 없으면 -1반환
}

void LogoutUI::PushLogoutButton(Logout *logout)
{
    if(loginState)  // 로그인 상태에서만 로그아웃 할 수 있다.
    {
        logout->DoLogout();
    }
    else
    {
        outputFile<<"로그인 상태에서 로그아웃 해주세요"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
        return;
    }
}

void LogoutUI::ShowCompleteLogoutMessage()
{
    //로그아웃이 완료되었다는 창을 띄우는 코드 (이번과제에서는 로그아웃한 회원의 아이디를 텍스트로 출력)
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
    inputFile>>input_memberName>>input_idCardNumber>>input_id>>input_pw;  // 회원의 기본정보입력

    signUp->getEssentailInfo(input_memberName, input_idCardNumber, input_id, input_pw); // 회원의 기본 정보를 컨트롤 클래스로 넘김
}

void SignUpUI::ShowEssentialInfoInputInterface()
{
    /*
    회원의 기본정보를 입력하는 창으로 이동하는 코드 구현(이번과제에서는 텍스트만 표현 하므로 코드 없음)
    */
}

void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
{
    // 회원가입 완료했다는 메세지 과제 형식에 맞게 출력
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
    bool signupPossible = true; //회원가입 가능하면 true 아니면 false

    for(int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);

        if(id==input_id)    // 벡터에 입력한 id가 존재하면 id 중복이 안되므로
        {
            signupPossible = false; // 가입이 불가능하다.
        }
    }
    
    if(signupPossible)  // 회원가입이 가능하면 (=겹치는 아이디없으면) 회원가입한다.
    {
        Member* m = new Member(input_id, input_pw, input_memberName, input_idCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(input_memberName, input_idCardNumber, input_id, input_pw);
    }
    else // 회원가입이 불가능하면 (=겹치는 아이디있으면) 회원가입 못하게한다.
    {
        outputFile<<"아이디가 겹쳐서 회원가입이 불가능 합니다"<<endl<<endl;   // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
    }
}

void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
{
    deleteMyAccount->DeleteAccount();
}

void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
{
    //회원탈퇴가 완료되었다는 창을 띄우는 코드 (이번과제에서는 회원탈퇴한 회원의 아이디를 텍스트로 출력)
    outputFile<<"> "<<curMemberID<<endl<<endl;
}

DeleteMyAccount::DeleteMyAccount()
{
    DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
    deleteMyAccountUI->DeleteAccountButton(this);
}

void DeleteMyAccount::DeleteAccount()
{
    if(loginState)  // 현재 로그인 중일때만 회원 탈퇴가 가능하다.
    {
        DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
        string curMemberID = curLoginMember->getID();   // 탈퇴하는 회원의 아이디 정보
        curLoginMember->~Member(); // 객체 삭제한다.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI에 회원 탈퇴가 되었다는 창을 띄운다
        curLoginMember=NULL; // 현재 로그인중인 회원 없음.
        loginState=false; // 로그아웃상태로 만든다.
    }
    else    // 로그아웃 상태에서 회원탈퇴 하는것은 안된다.
    {
        outputFile<<"로그인을 진행한 후에 회원탈퇴를 해주세요"<<endl<<endl;   // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
    }
}

/*
Function : SearchProduct::SearchProduct()
Description: 이 함수는 SearchProduct 클래스의 객체를 생성하는 생성자 함수입니다.
Parameters : void
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
SearchProduct::SearchProduct()
{
    SearchProductUI* searchProductUI = new SearchProductUI;
    searchProductUI->ShowSearchWindow();
    searchProductUI->InputProductName(this);
}

/*
Function : SearchProductUI::ShowSearchWindow()
Description: 검색 창을 보여주는 함수, 과제에서는 텍스트이기 때문에 아무 기능도 실행하지 않는다.
Parameters : void
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void SearchProductUI::ShowSearchWindow()
{

}

/*
Function : SearchProductUI::InputProductName()
Description: 상품 이름을 입력받는 함수
Parameters : SearchProduct* searchProduct
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void SearchProductUI::InputProductName(SearchProduct* searchProduct)
{
    string productName;             // 상품명

    inputFile >> productName;

    // if로 상품 있는지 없는지 검사코드 추가
    searchProduct->ShowProductInfo(productName);
}

/*
Function : SearchProduct::ShowProductInfo()
Description: 상품의 이름을 입력받아서 상품을 정보를 출력하는 함수
Parameters : string productName
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void SearchProduct::ShowProductInfo(string productName)
{
    vector <Product*> listSellingProducts;

    for (int i = 0; i < MemberLoginInfo.size(); i++)
    {
        listSellingProducts.clear();    // 매 반복마다 listSellingProducts 리스트 초기화

        Member* member = get<2>(MemberLoginInfo[i]);    // 반복문을 통해 모든 각 회원마다  

        listSellingProducts = member->ListSellingProducts();    // 판매중인 상품의 주소 포인터를 받아옴

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

                curSearchedProduct = listSellingProducts[j];  // 현재 검색한 상품명을 전역변수에 저장
            }
        }
    }
}

/*
Function : Product::CheckSelectedProduct()
Description: 검색한 상품의 이름이 등록되어있는 상품의 이름과 같은지 비교하는 함수
Parameters : string productName
Return Value : boolean (같으면 true, 다르면 false)
Created: 2022/5/29 7:00 pm
Author: 김진호
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
Description: 회원이 판매하고 있는 상품의 리스트를 반환하는 함수
Parameters : 없음
Return Value : vector <Product*> sellingProductListPointer
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
vector <Product*> Member::ListSellingProducts()
{
    return this->sellingProductListPointer; // 회원이 가지고 있는 판매중인 상품리스트를 vector <Product*> 타입으로 리턴한다.
}

/*
Function : PurchaseProduct::PurchaseProduct()
Description: 상품 구매 컨트롤 클래스
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
PurchaseProduct::PurchaseProduct()
{
    PurchaseProductUI* purchaseProductUI = new PurchaseProductUI;
    purchaseProductUI->PushPurchaseButton(this);
}

/*
Function : PurchaseProductUI::PushPurchaseButton()
Description: 회원이 구매 버튼을 누름
Parameters : PurchaseProduct* purchaseProduct
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void PurchaseProductUI::PushPurchaseButton(PurchaseProduct* purchaseProduct)
{
    purchaseProduct->ProceedPurchase();
}

/*
Function : PurchaseProduct::ProceedPurchase()
Description: 컨트롤 클래스에 버튼 누른 것 전달
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void PurchaseProduct::ProceedPurchase()
{
    if (curSearchedProduct->orderProduct() == true) // 해당 상품을 주문한다.
    {
        curLoginMember->AddPurchaseProduct(curSearchedProduct); // 구매한 상품리스트에 추가

        outputFile << "> ";
        outputFile << curSearchedProduct->getSellerID() << " ";
        outputFile << curSearchedProduct->getProductName() << endl << endl;

    }
    else
    {
        outputFile << "해당 상품은 재고가 없습니다.";
    }
}

/*
Function : Member::AddPurchaseProduct()
Description: 회원이 구매한 상품 리스트에 추가한다.
Parameters : Product* product
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void Member::AddPurchaseProduct(Product* product)
{
    this->purchasedProductListPointer.push_back(product);
}

/*
Function : Product::orderProduct()
Description: 선택한 상품에 대해 주문을 넣는 함수
Parameters : 없음
Return Value : boolean (재고가 있으면 true, 없으면 false)
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
bool Product::orderProduct()
{
    if (remainCount > 0)
    {
        remainCount--;  // 상품을 구매했기 때문에 재고 하나를 뺀다.
        return true;
    }
    else
        return false;
}

/*
Function : PurchaseHistory::PurchaseHistory()
Description: 상품 구매 내역 컨트롤 클래스를 생성하는 생성자
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
PurchaseHistory::PurchaseHistory()
{
    PurchaseHistoryUI* purchaseHIstoryUI = new PurchaseHistoryUI;
    purchaseHIstoryUI->PushPurchaseHistoryButton(this);
}

/*
Function : PurchaseHistoryUI::PushPurchaseHistoryButton()
Description: 회원이 구매 내역 조회 버튼을 누르는 것을 구현한 함수
Parameters : PurchaseHistory* purchaseHistory
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
void PurchaseHistoryUI::PushPurchaseHistoryButton(PurchaseHistory* purchaseHistory)
{
    purchaseHistory->ProceedPurchaseHistory();
}

/*
Function : PurchaseHistory::ProceedPurchaseHistory()
Description: 컨트롤 클래스에 버튼 누른 것을 전달
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
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
Description: 회원이 구매한 상품 리스트를 반환하는 함수
Parameters : 없음
Return Value : vector <Product*> purchasedProductListPointer
Created: 2022/5/29 7:00 pm
Author: 김진호
*/
vector <Product*> Member::ListPurchasedProduct()
{
    return this->purchasedProductListPointer;
}

/*
Function : RatingManagement::RatingManagement()
Description: 구매 만족도 입력 컨트롤 클래스를 생성하는 생성자
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
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
Description: 구매한 상품 중에서 하나를 선택하는 것을 구현한 함수
Parameters : RatingManagement* ratingManagement
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
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
Description: 상품을 선택하는 것을 전달하는 함수
Parameters : Product* selectedProduct
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingManagement::SendPurchasedProduct(Product* selectedProduct)
{
    this->selectedProduct = selectedProduct;
}

/*
Function : RatingUI::ActivateRatingButton()
Description: 선택한 상품의 구매 만족도 입력 버튼을 활성화하는 함수 (이 과제에서는 텍스트여서 아무 기능이 없다.)
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingUI::ActivateRatingButton()
{
    
}

/*
Function : RatingUI::PushRatingButton()
Description: 구매 만족도 입력을 누르는 것을 구현한 함수
Parameters : RatingManagement* ratingManagement
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingUI::PushRatingButton(RatingManagement* ratingManagement)
{
    ratingManagement->SendRatingButton();
}

/*
Function : RatingManagement::SendRatingButton()
Description: 버튼을 눌렀다를 전달하지만 텍스트임으로 아무것도 실행하지 않는다.
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingManagement::SendRatingButton()
{
    
}

/*
Function : RatingUI::ShowRatingInputWindow()
Description: 평점 입력창을 띄우지만 텍스트라 이번 과제에서는 기능이 없다.
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingUI::ShowRatingInputWindow()
{
    
}

/*
Function : RatingUI::CreateNewRating()
Description: 구매 만족도 입력 창에서 구매 만족도를 추가하는 함수
Parameters : RatingManagement* ratingManagement
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingUI::CreateNewRating(RatingManagement* ratingManagement)
{
    int ratingValue;

    inputFile >> ratingValue;

    ratingManagement->SendRating(ratingValue);
}

/*
Function : RatingManagement::SendRating()
Description: 입력한 구매 만족도를 전달하는 함수
Parameters : int ratingValue
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingManagement::SendRating(int ratingValue)
{
    Product* selectedProduct = this->getSelectedProduct();

    selectedProduct->requestEnrollRating(ratingValue);
}

/*
Function : Product::requestEnrollRating()
Description: 상품 클래스에 평점 등록을 요청하는 함수
Parameters : int ratingValue
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void Product::requestEnrollRating(int ratingValue)
{
    Rating* rating = new Rating;

    rating->newRating(ratingValue, this, curLoginMember->getMemberName());
}

/*
Function : Rating::newRating()
Description: 해당 상품의 구매 만족도를 등록하는 함수
Parameters : int ratingValue, Product* selectedProduct, string writer
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
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
Description: 해당 상품의 구매 만족도 리스트를 반환하는 함수
Parameters : 없음
Return Value : vector <Rating*> ratingListPointer
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
vector <Rating*> Product::ListRating()
{
    return this->ratingListPointer;
}

/*
Function : doTask()
Description: 기능을 실행하는 함수 (파일로부터 입력받아서 다양한 기능 수행)
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 최준수
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
                    outputFile<<"1.1. 회원가입"<<endl;

                    if(loginState)  // 현재 로그인중이라면 회원가입을 할 수 없다.
                    {
                        outputFile<<"로그아웃 후 회원가입을 진행해주세요"<<endl<<endl;    // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
                    }
                    else    // 로그아웃 상태에서만 회원가입을 할 수 있다.
                    {
                        SignUp *signUp = new SignUp;
                    }
                }
                else if(menu1 == 1 && menu2 == 2)
                {
                    outputFile<<"1.2. 회원탈퇴"<<endl;

                    DeleteMyAccount *deleteMyAccount = new DeleteMyAccount;
                }
                else if(menu1 == 2 && menu2 == 1)
                {
                    outputFile<<"2.1. 로그인"<<endl;

                    if(loginState)  // 로그인 상태에서는 로그인을 할 수 없다.
                    {
                        outputFile<<"로그인 할 수없습니다 로그아웃 후 사용해주세요"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
                    }
                    else // 로그아웃 상태에서만 로그인 할 수 있다.
                    {
                        Login *login = new Login;
                    }
                }
                else if(menu1 == 2 && menu2 == 2)
                {
                    outputFile<<"2.2. 로그아웃"<<endl;

                    Logout *logout = new Logout;

                }
                else if(menu1 == 3 && menu2 == 1)
                {
                    outputFile<<"3.1. 판매 의류 등록"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 3 && menu2 == 2)
                {
                    outputFile<<"3.2. 등록 상품 조회"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 3 && menu2 == 3)
                {
                    outputFile<<"3.3. 판매 완료 상품 조회"<<endl;
                    /*
                        구현부
                    */
                }
                else if(menu1 == 4 && menu2 == 1)
                {
                    outputFile<<"4.1. 상품 정보 검색"<<endl;
                    
                    SearchProduct* searchProduct = new SearchProduct;
        
                }
                else if(menu1 == 4 && menu2 == 2)
                {
                    outputFile<<"4.2. 상품 구매"<<endl;
                    
                    PurchaseProduct* purchaseProduct = new PurchaseProduct;
                }
                else if(menu1 == 4 && menu2 == 3)
                {
                    outputFile<<"4.3. 상품 구매 내역 조회"<<endl;
                    
                    PurchaseHistory* purchaseHistory = new PurchaseHistory;
                }
                else if(menu1 == 4 && menu2 == 4)
                {
                    outputFile<<"4.4. 상품 구매만족도 평가"<<endl;
                    
                    RatingManagement* ratingManagement = new RatingManagement;
                }
                else if(menu1 == 5 && menu2 == 1)
                {
                    outputFile<<"5.1. 판매 상품 통계"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 6 && menu2 ==1)
                {
                    outputFile<<"6.1. 종료"<<endl;
                    return ; //doTask 함수종료
                }
                getline(inputFile,str);
            }
        }
    }
}

/*
Function : main()
Description: 의류 판매 사이트 구현, inputFile로 정보를 입력받아 outputFile로 정보 출력
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 최준수
*/
int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}