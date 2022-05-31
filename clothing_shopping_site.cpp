#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile(INPUT_FILE_NAME);   // input.txt 를 읽기모드로 열음
ofstream outputFile(OUTPUT_FILE_NAME); // output.txt 를 쓰기모드로 얻음

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
    void GetEssentailInfo(string inputMemberName, string inputIDCardNumber, string inputID, string inputPW);
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
    void PushSignUpButton(SignUp* signUp);
    void ShowEssentialInfoInputInterface();
    void InputEssentialInfo(SignUp* signUp);
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
    void DeleteAccountButton(DeleteMyAccount* deleteMyAccount);
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
    bool IDPWinputed(string inputID, string inputPW);
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
    bool InputIDPW(Login* login);
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
    void PushLogoutButton(Logout* logout);
    void ShowCompleteLogoutMessage();
};

class AddProduct
{
private:

public:
    AddProduct();
    void ShowAddUI();
    void SendProductData(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);
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
    void ShowPurchaseHistory();
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

public:
    RatingManagement();
    void SendPurchasedProduct();
    void SendRatingButton();
    void SendRating(string productName, int ratingValue);
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
    void NewRating(int ratingValue, string productName, string writer);
    int GetRating() { return ratingValue; }
};

class Product
{
protected:
    string productName, madeCompanyName, sellerID;
    int price, productCount, remainCount, sellingCount;

    vector <Rating*> ratingListPointer;  // 평점리스트 포인터

public:
    Product(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);
    string GetSellerID() { return sellerID; }   // 판매자ID 반환 
    string GetProductName() { return productName; }
    string GetMadeCompanyName() { return madeCompanyName; }
    int GetPrice() { return price; }
    int GetRemainCount() { return remainCount; }    // 남은 수량 반환
    int GetProductCount() { return productCount; }
    int GetSellingCount() { return sellingCount; }  // 판매 수량 반환
    vector <Rating*> ListRating();

    void AddRating(Rating* newRating);
    int GetSum();
    double GetAverageRating();
    bool CheckSelectedProduct(string productName);
    void SoldoutProduct(Product* soldoutProduct);
    bool OrderProduct();
    void RequestEnrollRating(int rating);
};

/*
Class: Member
Description: 회원 엔티티 클래스이다.
Created: 2022/5/25 5:00 am
Author: 최준수
mail: cys4439@naver.com
*/
class Member
{
private:
    string id, pw, memberName, idCardNumber;
    vector <Product*> purchasedProductListPointer;  // 구매한 상품리스트
    vector <Product*> sellingProductListPointer;    // 판매중인 상품객체의 주소를 포인터하는 리스트임
    vector <Product*> soldoutProductListPointer;    // 판매완료된 상품객체의 주소를 가리키는 리스트
    vector <Product*> allSalesProductListPointer;   // 판매완료, 판매중 모든 상품 객체의 주소를 가리키는 리스트

public:
    string GetID() { return id; }  // 개체의 id를 get하는 함수
    string GetPW() { return pw; }  // 개체의 pw를 get하는 함수
    string GetMemberName() { return memberName; }  // 개체의 이름을 get하는 함수
    string GetIDCardNumber() { return idCardNumber; }  // 개체의 주민번호를 get하는 함수
    int CheckIDPW(string inputID, string inputPW); // 입력받은 id, pw가 매칭되는지 확인하는 함수

    Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber); //생성자
    ~Member(); //파괴자

    void AddPurchaseProduct(Product* product);
    void AddNewProduct(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount);
    void AddRegistedNewProuduct(Product* newProduct);
    void AddSoldoutProduct(Product* soldoutproduct);
    void AddAllSalesProduct(Product* newProduct);
    vector <Product*> ListPurchasedProduct();
    vector <Product*> ListSellingProducts(); //판매중인 상품리스트를 가리키는 포인터
    vector <Product*> ListSoldoutProducts(); //판매완료된 상품 리스트를 가리키는 포인터
    vector <Product*> ListAllsalesProducts(); //판매중인 상품과 판매완료된 상품 모두를 가리키는 포인터
};

vector < tuple<string, string, Member*> > memberLoginInfo; //벡터의 첫값은 id , 두번째 값은 pw , 세번째 값은 Member개체의 주소를가리키는 포인터 정보를 담음
Member* curLoginMember; // 현재 로그인중인 회원의 정보를 전역으로 설정
bool loginState = false; // 현재 로그인중이면 true 로그아웃중이면 false 정보를 전역으로 설정

Product* curSearchedProduct;  // 현재 검색한 상품을 전역으로 설정

Product::Product(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)   // 과제2 모델링의 이름이 CreateProduct에 해당 CreateProduct 이름을 바꿔 그냥 생성자로 했음
{
    sellerID = curLoginMember->GetID();
    productName = inputProductName;
    madeCompanyName = inputMadeCompanyName;
    price = inputPrice;
    productCount = inputProductCount;
    remainCount = productCount; // 생성되었을때는 남은 수량 = 수량
    sellingCount = 0;   // 생성되었을때는 판 수량 = 0

    curLoginMember->AddRegistedNewProuduct(this);   // 현재 로그인 한 회원이 판매중인 상품을 리스트에 추가한다
    curLoginMember->AddAllSalesProduct(this);

    outputFile << "> ";
    outputFile << this->productName << " " << this->madeCompanyName << " " << this->price << " " << this->productCount << endl << endl; // 생성한 상품 객체의 이름, 제조회사명, 가격 ,수량을 출력한다.
}

int Product::GetSum()
{
    int sum = 0;
    int price = this->GetPrice();
    int sellingCount = this->GetSellingCount();

    sum = price * sellingCount;
    return sum;
}

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
        return averageRating;
    }
}

void Product::AddRating(Rating* newRating)
{
    (this->ratingListPointer).push_back(newRating);
}

/*
Function : Member::Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber)
Description: 이 함수는 Member 클래스의 객체를 생성하는 생성자 함수입니다.
Parameters :
string input_id - 입력된 id
string input_pw - 입력된 pw
string input_memberName - 입력된 회원의 이름
string input_idCardNumber - 입력된 주민번호
Return Value : 없음
Created: 2022/5/25 5:00 am
Author: 최준수
*/
Member::Member(string inputID, string inputPW, string inputMemberName, string inputIDCardNumber)
{
    id = inputID;
    pw = inputPW;
    memberName = inputMemberName;
    idCardNumber = inputIDCardNumber;

    memberLoginInfo.push_back({ this->GetID(), this->GetPW(), this }); // 입력된 회원의 정보를 MemberLoginInfo에 푸쉬한다.
}

/*
Function : Member::~Member()
Description: 이 함수는 Member 클래스의 객체를 파괴하는 파괴자 함수입니다.
Parameters : void
Return Value : 없음
Created: 2022/5/25 5:00 am
Author: 최준수
*/
Member::~Member()
{
    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);
        string pw = get<1>(memberLoginInfo[i]);
        Member* pointerOfAddress = get<2>(memberLoginInfo[i]);
        // MemberLoginInfo 벡터에 들어있는 각 개체별 id, pw, 객체의 주소 포인터


        string idOfCurObject = this->GetID(); // 현재 멤버의 객체의 id
        string pwOfCurObject = this->GetPW(); // 현재 멤버의 객체의 pw
        Member* pointerOfCurObject = this; // 현재 멤버의 객체의 주소 포인터

        if (idOfCurObject == id && pwOfCurObject == pw && pointerOfCurObject == pointerOfAddress) // 현재 멤버가 가지고있는 정보를 MemberLoginInfo로부터 지운다.
        {
            memberLoginInfo.erase(memberLoginInfo.begin() + i);
            break;
        }
    }
}

void Member::AddNewProduct(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
{
    Product* newProduct = new Product(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount); // 받은 정보로 상품 객체를 생성한다
}

void Member::AddRegistedNewProuduct(Product* newProduct)
{
    sellingProductListPointer.push_back(newProduct);
}

void Member::AddSoldoutProduct(Product* soldoutProduct)
{
    (this->soldoutProductListPointer).push_back(soldoutProduct);
}

void Member::AddAllSalesProduct(Product* newProduct)
{
    allSalesProductListPointer.push_back(newProduct);
}

vector <Product*> Member::ListSellingProducts()
{
    return this->sellingProductListPointer; // 리턴 타입은 vector <Product*> 타입이다
}

vector <Product*> Member::ListSoldoutProducts()
{
    return this->soldoutProductListPointer; // 리턴 타입은 vector <Product*> 타입이다
}

vector <Product*> Member::ListAllsalesProducts()
{
    return this->allSalesProductListPointer; // 리턴 타입은 vector <Product*> 타입이다
}

/*
Function : bool LoginUI::inputIDPW(Login* login)
Description: 이 함수는 로그인시 id와 pw를 입력하는 함수입니다.
Parameters : Login* login - 로그인 클래스의 객체의 주소를 가리키는 포인터
Return Value : bool
Created: 2022/5/26 3:00 am
Author: 최준수
*/
bool LoginUI::InputIDPW(Login* login)
{
    string inputID, inputPW;
    inputFile >> inputID >> inputPW;    // UI에 id, pw 입력

    return login->IDPWinputed(inputID, inputPW);   //컨트롤 클래스에게 입력한 id, pw 전달
}

/*
Function : void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
Description: 이 함수는 로그인 완료시 로그인 한 회원의 id와 pw를 출력하는 함수입니다.
Parameters :
string curLoginMemberID - 로그인 한 회원의 id
string curLoginMemberPW - 로그인 한 회원의 pw
Return Value : void
Created: 2022/5/26 3:00 am
Author: 최준수
*/
void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
{
    //로그인이 완료되었다는 창을 띄우는 코드 (이번과제에서는 로그인한 회원의 아이디 비밀번호를 텍스트로 출력)
    outputFile << "> " << curLoginMemberID << " " << curLoginMemberPW << endl << endl;
}

/*
Function : Login::Login()
Description: 이 함수는 Login 클래스의 객체를 생성하는 생성자 함수입니다.
Parameters : void
Return Value : 없음
Created: 2022/5/26 3:00 am
Author: 최준수
*/
Login::Login()
{
    LoginUI* loginUI = new LoginUI;

    if (loginUI->InputIDPW(this))   // id pw를 입력한다. 로그인이 가능하면 (입력한 id와 입력한 pw가 매칭이 맞는경우) 로그인 한다.
    {
        loginState = true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->GetID(), curLoginMember->GetPW());
    }
}

/*
Function : bool Login::IDPWinputed(string input_id, string input_pw)
Description: 이 함수는 UI로부터 입력받은 id, pw를 컨트롤 클래스에 전달하는 함수입니다.
Parameters :
string input_id - 입력된 id
string input_pw - 입력된 pw
Return Value : bool
Created: 2022/5/26 3:00 am
Author: 최준수
*/
bool Login::IDPWinputed(string inputID, string inputPW)
{
    if (curLoginMember->CheckIDPW(inputID, inputPW) != -1) // id와 pw가 매칭되면
    {
        curLoginMember = get<2>(memberLoginInfo[curLoginMember->CheckIDPW(inputID, inputPW)]); // 매칭된 id,pw의 회원으로 현재 로그인중인 회원의 정보를 설정함
        return true;    // 로그인 가능하므로 true 반환
    }
    return false;   // 로그인 불가능하면 false 반환
}

/*
Function : int Member::checkIDPW(string input_id,string input_pw)
Description: 이 함수는 로그인할때 입력받은 id와 pw가 서로 매칭이 되는지 확인하는 함수입니다.
Parameters :
string input_id - 입력된 id
string input_pw - 입력된 pw
Return Value : int
Created: 2022/5/25 5:00 am
Author: 최준수
*/
int Member::CheckIDPW(string inputID, string inputPW)
{
    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);
        string pw = get<1>(memberLoginInfo[i]);
        if (id == inputID && pw == inputPW) // 입력한 id와 pw가 매칭 되면
        {
            return i; // 인덱스 반환
        }
    }
    return -1; // 매칭이 되는것이 없으면 -1반환
}

/*
Function : LogoutUI::PushLogoutButton(Logout *logout)
Description: 이 함수는 로그아웃 버튼을 누르면 로그아웃을 진행하는 함수입니다.
Parameters : Logout *logout - Logout 객체의 주소를 가리키는 포인터
Return Value : void
Created: 2022/5/26 3:00 am
Author: 최준수
*/
void LogoutUI::PushLogoutButton(Logout* logout)
{
    if (loginState)  // 로그인 상태에서만 로그아웃 할 수 있다.
    {
        logout->DoLogout();
    }
}

/*
Function : void LogoutUI::ShowCompleteLogoutMessage()
Description: 이 함수는 로그아웃을 완료했을때 로그아웃한 회원의 id를 출력하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: 최준수
*/
void LogoutUI::ShowCompleteLogoutMessage()
{
    //로그아웃이 완료되었다는 창을 띄우는 코드 (이번과제에서는 로그아웃한 회원의 아이디를 텍스트로 출력)
    outputFile << "> " << curLoginMember->GetID() << endl << endl;
}

/*
Function : Logout::Logout()
Description: 이 함수는 Logout 객체를 생성하는 생성자 함수입니다.
Parameters : void
Return Value : 없음
Created: 2022/5/26 3:00 am
Author: 최준수
*/
Logout::Logout()
{
    LogoutUI* logoutUI = new LogoutUI(); logoutUI->PushLogoutButton(this);
}

/*
Function : void Logout::DoLogout()
Description: 이 함수는 로그아웃작업을 실제로 진행하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: 최준수
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
Description: 이 함수는 회원가입 버튼 누르면 회원가입을 진행하는 함수입니다.
Parameters : SignUp *signUp - SignUp 클래스 객체의 포인터
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUpUI::PushSignUpButton(SignUp* signUp)
{
    signUp->ProceedSignUp();
}

/*
Function : void SignUpUI::InputEssentialInfo(SignUp *signUp)
Description: 이 함수는 회원의 기본정보(id, pw, 회원이름, 회원주민번호)를 입력하는 함수입니다.
Parameters : SignUp *signUp - SignUp 클래스 객체의 포인터
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUpUI::InputEssentialInfo(SignUp* signUp)
{
    string inputID, inputPW, inputMemberName, inputIDCardNumber;
    inputFile >> inputMemberName >> inputIDCardNumber >> inputID >> inputPW;  // 회원의 기본정보입력

    signUp->GetEssentailInfo(inputMemberName, inputIDCardNumber, inputID, inputPW); // 회원의 기본 정보를 컨트롤 클래스로 넘김
}

/*
Function : void SignUpUI::ShowEssentialInfoInputInterface()
Description: 이 함수는 회원의 기본정보를 입력하는 인터페이스를 회원에게 보여주는 함수입니다
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUpUI::ShowEssentialInfoInputInterface()
{
    /*
    회원의 기본정보를 입력하는 창으로 이동하는 코드 구현(이번과제에서는 텍스트만 표현 하므로 코드 없음)
    */
}

/*
Function : void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
Description: 이 함수는 회원가입을 완료했했을때 회원의 이름, 회원의 주민번호, 회원의 id, 회원의 pw를 출력하는 함수입니다.
Parameters :
string memberName - 회원의 이름
string memberIDCardNumber - 회원의 주민번호
string memberID - 회원의 id
string memberPW - 회원의 pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
{
    // 회원가입 완료했다는 메세지 과제 형식에 맞게 출력
    outputFile << "> " << memberName << " " << memberIDCardNumber << " " << memberID << " " << memberPW << endl << endl;
}

/*
Function : SignUp::SignUp()
Description: 이 함수는 SignUp 객체를 생성하는 생성자 함수입니다.
Parameters : void
Return Value : 없음
Created: 2022/5/26 6:00 am
Author: 최준수
*/
SignUp::SignUp()
{
    SignUpUI* signUpUI = new SignUpUI;
    signUpUI->PushSignUpButton(this);
    signUpUI->InputEssentialInfo(this);
}

/*
Function : void SignUp::ProceedSignUp()
Description: 이 함수는 회원가입을 계속해서 진행하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUp::ProceedSignUp()
{
    SignUpUI* signUpUI = new SignUpUI;
    signUpUI->ShowEssentialInfoInputInterface();
}

/*
Function : void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
Description: 이 함수는 입력받은 회원의이름, 주민번호, 입력된 id, 입력된 pw 정보를 get하여 회원가입 작업을 실제로 진행하는 함수입니다.
Parameters :
string input_memberName - 입력받은 회원의 이름
string input_idCardNumber - 입력받은 회원의 주민번호
string input_id - 입력받은 회원의 id
string input_pw - 입력받은 회원의 pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUp::GetEssentailInfo(string inputMemberName, string inputIDCardNumber, string inputID, string inputPW)
{
    bool signupPossible = true; //회원가입 가능하면 true 아니면 false

    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        string id = get<0>(memberLoginInfo[i]);

        if (id == inputID)    // 벡터에 입력한 id가 존재하면 id 중복이 안되므로
        {
            signupPossible = false; // 가입이 불가능하다.
        }
    }

    if (signupPossible)  // 회원가입이 가능하면 (=겹치는 아이디없으면) 회원가입한다.
    {
        Member* m = new Member(inputID, inputPW, inputMemberName, inputIDCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(inputMemberName, inputIDCardNumber, inputID, inputPW);
    }
}

/*
Function : void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
Description: 이 함수는 회원탈퇴 버튼을 누르면 회원탈퇴를 진행하는 함수입니다.
Parameters : DeleteMyAccount *deleteMyAccount - DeleteMyAccount 클래스의 객체의 주소를 가리키는 포인터
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount* deleteMyAccount)
{
    deleteMyAccount->DeleteAccount();
}

/*
Function : void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
Description: 이 함수는 회원탈퇴를 완료 했을때 탈퇴한 회원의 id를 출력하는 합수입니다.
Parameters : string curMemberID - 탈퇴한 회원의 id
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
{
    //회원탈퇴가 완료되었다는 창을 띄우는 코드 (이번과제에서는 회원탈퇴한 회원의 아이디를 텍스트로 출력)
    outputFile << "> " << curMemberID << endl << endl;
}

/*
Function : DeleteMyAccount::DeleteMyAccount()
Description: 이 함수는 DeleteMyAccount 클래스의 객체를 생성하는 생성자 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
DeleteMyAccount::DeleteMyAccount()
{
    DeleteMyAccountUI* deleteMyAccountUI = new DeleteMyAccountUI;
    deleteMyAccountUI->DeleteAccountButton(this);
}

/*
Function : DeleteMyAccount::DeleteAccount()
Description: 이 함수는 회원탈퇴 작업을 실제로 진행하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void DeleteMyAccount::DeleteAccount()
{
    if (loginState)  // 현재 로그인 중일때만 회원 탈퇴가 가능하다.
    {
        DeleteMyAccountUI* deleteMyAccountUI = new DeleteMyAccountUI;
        string curMemberID = curLoginMember->GetID();   // 탈퇴하는 회원의 아이디 정보
        curLoginMember->~Member(); // 객체 삭제한다.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI에 회원 탈퇴가 되었다는 창을 띄운다
        curLoginMember = NULL; // 현재 로그인중인 회원 없음.
        loginState = false; // 로그아웃상태로 만든다.
    }
}

AddProduct::AddProduct()
{
    if (loginState)  // 로그인 중 상태 일 때만 판매 의류를 등록 할 수있다.
    {
        AddProductUI* addProductUI = new AddProductUI;
        addProductUI->AddProductButton(this);
        addProductUI->InputProductData(this);
    }
}

void AddProduct::ShowAddUI()
{
    AddProductUI* addProductUI = new AddProductUI;
    addProductUI->StartInterface();
}

void AddProduct::SendProductData(string inputProductName, string inputMadeCompanyName, int inputPrice, int inputProductCount)
{
    curLoginMember->AddNewProduct(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount);   // 현재 로그인 한 회원이 새 상품을 등록하는 함수를 호출한다
}

void AddProductUI::AddProductButton(AddProduct* addProduct)
{
    addProduct->ShowAddUI();
}

void AddProductUI::StartInterface()
{
    /*
    상품의 정보를 입력하는 창으로 이동하는 코드 구현(이번과제에서는 텍스트만 표현 하므로 코드 없음)
    */
}

void AddProductUI::InputProductData(AddProduct* addProduct)
{
    string inputProductName, inputMadeCompanyName;
    int inputPrice, inputProductCount;

    inputFile >> inputProductName >> inputMadeCompanyName >> inputPrice >> inputProductCount;   // 상품명, 제조회사명, 가격, 수량을 파일로 부터 입력받는다.

    addProduct->SendProductData(inputProductName, inputMadeCompanyName, inputPrice, inputProductCount); // 입력받은 정보를 컨트롤 클래스로 전해준다.
}

ViewProduct::ViewProduct()
{
    if (loginState)  // 로그인 상태에서만 판매중인 의류를 조회 가능하다.
    {
        ViewProductUI* viewProductUI = new ViewProductUI;

        viewProductUI->ViewSalesProductButton(this);
    }
}

void ViewProduct::ShowSellingProduct()
{
    vector <Product*> listSellingProducts;
    // listSellingProducts는 ListSellingProducts() 함수로부터 현재 로그인한 회원이 판매중인 상품의 주소들을 포인터하는 리스트를 반환받기 위한 벡터임

    listSellingProducts = curLoginMember->ListSellingProducts(); // 과제2 판매의류 조회 1.1.1에 해당

    for (int i = 0; i < listSellingProducts.size(); i++) // 각 상품의 주소의 포인터들을 받아왔으니 반복문을 통해 상세정보를 출력한다. 과제 2 판매의류 조회 1.1.2에 해당
    {
        outputFile << "> ";
        outputFile << listSellingProducts[i]->GetProductName() << " " << listSellingProducts[i]->GetMadeCompanyName() << " " << listSellingProducts[i]->GetPrice() << " " << listSellingProducts[i]->GetProductCount() << endl;
    }

    outputFile << endl;
}

void ViewProductUI::ViewSalesProductButton(ViewProduct* viewProduct)
{
    viewProduct->ShowSellingProduct();
}

ViewSoldoutProduct::ViewSoldoutProduct()
{
    if (loginState)  // 로그인 상태에서만 판매완료된 의류를 조회 가능하다.
    {
        ViewSoldoutProductUI* viewSoldoutProductUI = new ViewSoldoutProductUI;

        viewSoldoutProductUI->ViewSoldoutProductButton(this);
    }
}

void ViewSoldoutProductUI::ViewSoldoutProductButton(ViewSoldoutProduct* viewSoldoutProduct)
{
    viewSoldoutProduct->ShowSoldoutProduct();
}

void ViewSoldoutProduct::ShowSoldoutProduct()
{
    vector <Product*> listSoldoutProducts;
    vector <tuple <string, string, int, int, double> > v;
 
    listSoldoutProducts = curLoginMember->ListSoldoutProducts();

    for (int i = 0; i < listSoldoutProducts.size(); i++) // 각 상품의 주소의 포인터들을 받아왔으니 반복문을 통해 상세정보를 출력한다. 과제 2 판매의류 조회 1.1.2에 해당
    {
        string productName = listSoldoutProducts[i]->GetProductName();
        string madeCompanyName = listSoldoutProducts[i]->GetMadeCompanyName();
        int price = listSoldoutProducts[i]->GetPrice();
        int sellingCount = listSoldoutProducts[i]->GetSellingCount();
        double averageRating = listSoldoutProducts[i]->GetAverageRating();
        v.push_back({ productName, madeCompanyName, price, sellingCount, averageRating });    
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < v.size(); j++)
    {
        outputFile << "> ";
        outputFile << get<0>(v[j]) << " ";
        outputFile << get<1>(v[j]) << " ";
        outputFile << get<2>(v[j]) << " ";
        outputFile << get<3>(v[j]) << " ";
        outputFile << get<4>(v[j]) << endl;
    }
    
    outputFile << endl;
}


ProductSalesStats::ProductSalesStats()
{
    if (loginState) //로그인 상태 확인
    {
        ProductSalesStatsUI* productSalesStats = new ProductSalesStatsUI;

        productSalesStats->SalesStatsButton(this);
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
        listAllSalesProduct = curLoginMember->ListAllsalesProducts(); //현재 로그인된 회원의 모든 상품 리스트를 가져온다.

        for (int i = 0; i < listAllSalesProduct.size(); i++)
        {
            outputFile << "> ";
            outputFile << listAllSalesProduct[i]->GetProductName() << " ";
            outputFile << listAllSalesProduct[i]->GetSum() << " ";
            outputFile << listAllSalesProduct[i]->GetAverageRating() << " ";
            outputFile << endl;
        }
        outputFile << endl;
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

    for (int i = 0; i < memberLoginInfo.size(); i++)
    {
        listSellingProducts.clear();    // 매 반복마다 listSellingProducts 리스트 초기화

        Member* member = get<2>(memberLoginInfo[i]);    // 반복문을 통해 모든 각 회원마다  

        listSellingProducts = member->ListSellingProducts();    // 판매중인 상품의 주소 포인터를 받아옴

        for (int j = 0; j < listSellingProducts.size(); j++)
        {
            if (listSellingProducts[j]->CheckSelectedProduct(productName) == true)
            {
                outputFile << "> ";
                outputFile << listSellingProducts[j]->GetSellerID() << " ";
                outputFile << listSellingProducts[j]->GetProductName() << " ";
                outputFile << listSellingProducts[j]->GetMadeCompanyName() << " ";
                outputFile << listSellingProducts[j]->GetPrice() << " ";
                outputFile << listSellingProducts[j]->GetRemainCount() << " ";
                outputFile << listSellingProducts[j]->GetAverageRating();
                outputFile << endl << endl;

                curSearchedProduct = listSellingProducts[j];  // 현재 검색한 상품명을 전역변수에 저장
                return;
            }
        }
    }
    curSearchedProduct = NULL;
    return;
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
    if (this->productName == productName && this->GetRemainCount() > 0)
        return true;
    else
        return false;
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
    if (curSearchedProduct->OrderProduct() == true) // 해당 상품을 주문한다.
    {
        curLoginMember->AddPurchaseProduct(curSearchedProduct); // 구매한 상품리스트에 추가

        outputFile << "> ";
        outputFile << curSearchedProduct->GetSellerID() << " ";
        outputFile << curSearchedProduct->GetProductName() << endl << endl;

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
bool Product::OrderProduct()
{
    if (remainCount > 0)
    {
        remainCount--;  // 상품을 구매했기 때문에 재고 하나를 뺀다.

        sellingCount++; //상품을 구매했기 때문에 구매수를 하나 올린다.

        if (remainCount == 0)
        {
            this->SoldoutProduct(this);
        }
        return true;
    }
    else
        return false;
}

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
    purchaseHistory->ShowPurchaseHistory();
}

/*
Function : PurchaseHistory::ShowPurchaseHistory()
Description: 구매내역을 출력하는 함수
Parameters : 없음
Return Value : 없음
Created: 2022/5/29 7:00 pm
Author: 김진호
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
void RatingUI::SelectPurchasedProduct(RatingManagement* ratingManagement)
{
    ratingManagement->SendPurchasedProduct();
}

/*
Function : RatingManagement::SendPurchasedProduct()
Description: 상품을 선택하는 것을 전달하는 함수 (텍스트이기 때문에 기능이 없다)
Parameters : Product* selectedProduct
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingManagement::SendPurchasedProduct()
{

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
    string productName;
    int ratingValue;

    inputFile >> productName >> ratingValue;

    ratingManagement->SendRating(productName, ratingValue);
}

/*
Function : RatingManagement::SendRating()
Description: 입력한 구매 만족도를 전달하는 함수
Parameters : int ratingValue
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void RatingManagement::SendRating(string productName, int ratingValue)
{
    vector<Product*> purchasedList = curLoginMember->ListPurchasedProduct();

    for (int i = 0; i < purchasedList.size(); i++)
    {
        if (productName == purchasedList[i]->GetProductName())
            purchasedList[i]->RequestEnrollRating(ratingValue);
    }
}

/*
Function : Product::requestEnrollRating()
Description: 상품 클래스에 평점 등록을 요청하는 함수
Parameters : int ratingValue
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
*/
void Product::RequestEnrollRating(int ratingValue)
{
    Rating* rating = new Rating;

    rating->NewRating(ratingValue, this->GetProductName(), curLoginMember->GetMemberName());
}

/*
Function : Rating::newRating()
Description: 해당 상품의 구매 만족도를 등록하는 함수
Parameters : int ratingValue, string productName, string writer
Return Value : 없음
Created: 2022/5/29 9:00 pm
Author: 김진호
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

    outputFile << "> ";
    outputFile << sellerID << " ";
    outputFile << productName << " ";
    outputFile << ratingValue << endl << endl;
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
Function : void doTask()
Description: 이 함수는 입력받은 메뉴에 따라 해당 메뉴의 작업을 하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/25 : 3:00 pm
Author: 최준수
*/
void doTask() {
    if (inputFile.is_open())    //파일이 열려있는지 확인
    {
        while (!inputFile.eof())    //파일의 끝까지 읽는것을 반복
        {
            string str;

            while (1)
            {
                int menu1, menu2;
                inputFile >> menu1 >> menu2;    // 파일로부터 메뉴2개 를 입력받음

                if (menu1 == 1 && menu2 == 1)
                {
                    outputFile << "1.1. 회원가입" << endl;

                    if (!loginState)
                    {
                        SignUp* signUp = new SignUp;
                    }
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile << "1.2. 회원탈퇴" << endl;

                    DeleteMyAccount* deleteMyAccount = new DeleteMyAccount;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile << "2.1. 로그인" << endl;

                    if (!loginState)  // 로그인 상태에서는 로그인을 할 수 없다.
                    {
                        Login* login = new Login;
                    }
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile << "2.2. 로그아웃" << endl;

                    Logout* logout = new Logout;

                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile << "3.1. 판매 의류 등록" << endl;

                    AddProduct* addProduct = new AddProduct;

                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile << "3.2. 등록 상품 조회" << endl;

                    ViewProduct* viewProduct = new ViewProduct;

                }
                else if (menu1 == 3 && menu2 == 3)
                {
                    outputFile << "3.3. 판매 완료 상품 조회" << endl;

                    ViewSoldoutProduct* viewSoldoutProduct = new ViewSoldoutProduct;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile << "4.1. 상품 정보 검색" << endl;

                    SearchProduct* searchProduct = new SearchProduct;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile << "4.2. 상품 구매" << endl;

                    PurchaseProduct* purchaseProduct = new PurchaseProduct;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile << "4.3. 상품 구매 내역 조회" << endl;

                    PurchaseHistory* purchaseHistory = new PurchaseHistory;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile << "4.4. 상품 구매만족도 평가" << endl;

                    RatingManagement* ratingManagement = new RatingManagement;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile << "5.1. 판매 상품 통계" << endl;

                    ProductSalesStats* productSalesStats = new ProductSalesStats;
                }
                else if (menu1 == 6 && menu2 == 1)
                {
                    outputFile << "6.1. 종료" << endl;
                    return; //doTask 함수종료
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
Description: 의류 판매 사이트 구현, inputFile로 정보를 입력받아 outputFile로 정보 출력
Parameters : 없음
Return Value : 정상종료
Created: 2022/5/29 9:00 pm
Author: 최준수
*/
int main() {
    outputFile << fixed;
    outputFile.precision(1);

    doTask();
    inputFile.close();
    outputFile.close();
}