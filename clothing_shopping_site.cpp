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

public:
	string getID(){return id;}  // 개체의 id를 get하는 함수
	string getPW(){return pw;}  // 개체의 pw를 get하는 함수
	string getMemberName(){return memberName;}  // 개체의 이름을 get하는 함수
	string getIDCardNumber(){return idCardNumber;}  // 개체의 주민번호를 get하는 함수
	Member* address_of_object(){return this;}   // 각 개체의 주소를 get하는 함수
    int checkIDPW(string input_id,string input_pw); // 입력받은 id, pw가 매칭되는지 확인하는 함수

	Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //생성자
	~Member(); //파괴자
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //벡터의 첫값은 id , 두번째 값은 pw , 세번째 값은 Member개체의 주소를가리키는 포인터 정보를 담음
Member* curLoginMember; // 현재 로그인중인 회원의 정보를 전역으로 설정
bool loginState = false; // 현재 로그인중이면 true 로그아웃중이면 false 정보를 전역으로 설정

/*
Function : Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
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
Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
{
	id = input_id;
	pw = input_pw;
	memberName = input_memberName;
	idCardNumber = input_idCardNumber;

    MemberLoginInfo.push_back({this->getID(), this->getPW(), this->address_of_object()}); // 입력된 회원의 정보를 MemberLoginInfo에 푸쉬한다.
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
    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);
        string pw = get<1>(MemberLoginInfo[i]);
        Member *pointer_Of_Address = get<2>(MemberLoginInfo[i]);
        // MemberLoginInfo 벡터에 들어있는 각 개체별 id, pw, 객체의 주소 포인터


        string id_Of_CurObject = this->getID(); // 현재 멤버의 객체의 id
        string pw_Of_CurObject = this->getPW(); // 현재 멤버의 객체의 pw
        Member *pointer_Of_CurObject = this->address_of_object(); // 현재 멤버의 객체의 주소 포인터

        if (id_Of_CurObject == id && pw_Of_CurObject == pw && pointer_Of_CurObject == pointer_Of_Address) // 현재 멤버가 가지고있는 정보를 MemberLoginInfo로부터 지운다.
        {
            MemberLoginInfo.erase(MemberLoginInfo.begin() + i);
            break;
        }
    }
}

/*
Function : bool LoginUI::inputIDPW(Login* login)
Description: 이 함수는 로그인시 id와 pw를 입력하는 함수입니다.
Parameters : Login* login - 로그인 클래스의 객체의 주소를 가리키는 포인터
Return Value : bool
Created: 2022/5/26 3:00 am
Author: 최준수
*/
bool LoginUI::inputIDPW(Login* login)
{
    string input_id, input_pw;
    inputFile>>input_id>>input_pw;    // UI에 id, pw 입력

    return login->IDPWinputed(input_id,input_pw);   //컨트롤 클래스에게 입력한 id, pw 전달
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
    outputFile<<"> "<<curLoginMemberID<<" "<<curLoginMemberPW<<endl<<endl;
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
    LoginUI *loginUI = new LoginUI;

    if (loginUI->inputIDPW(this))   // id pw를 입력한다. 로그인이 가능하면 (입력한 id와 입력한 pw가 매칭이 맞는경우) 로그인 한다.
    {
        loginState=true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->getID(), curLoginMember->getPW());
    }
    else    // 로그인이 불가능하면 (입력한 id와 입력한 pw가 매칭이 아닌경우) 로그인 하지 못하게 한다.
    {
        outputFile<<"회원 정보가 없거나 id와 pw가 매칭이 되지않습니다. 로그인 실패"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
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
bool Login::IDPWinputed(string input_id, string input_pw)
{
    if (curLoginMember->checkIDPW(input_id,input_pw)!=-1) // id와 pw가 매칭되면
    {
        curLoginMember=get<2>(MemberLoginInfo[curLoginMember->checkIDPW(input_id, input_pw)]); // 매칭된 id,pw의 회원으로 현재 로그인중인 회원의 정보를 설정함
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
int Member::checkIDPW(string input_id,string input_pw)
{
    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);
        string pw=get<1>(MemberLoginInfo[i]);
        if (id == input_id && pw == input_pw) // 입력한 id와 pw가 매칭 되면
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
void LogoutUI::PushLogoutButton(Logout *logout)
{
    if (loginState)  // 로그인 상태에서만 로그아웃 할 수 있다.
    {
        logout->DoLogout();
    }
    else
    {
        outputFile<<"로그인 상태에서 로그아웃 해주세요"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
        return;
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
    outputFile<<"> "<<curLoginMember->getID()<<endl<<endl;
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
    LogoutUI *logoutUI = new LogoutUI(); logoutUI->PushLogoutButton(this);
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
    LogoutUI *logoutUI = new LogoutUI;
    logoutUI->ShowCompleteLogoutMessage();
    curLoginMember=NULL;
    loginState=false;
}

/*
Function : void SignUpUI::PushSignUpButton(SignUp *signUp)
Description: 이 함수는 회원가입 버튼 누르면 회원가입을 진행하는 함수입니다.
Parameters : SignUp *signUp - SignUp 클래스 객체의 포인터
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void SignUpUI::PushSignUpButton(SignUp *signUp)
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
void SignUpUI::InputEssentialInfo(SignUp *signUp)
{
    string input_id, input_pw, input_memberName, input_idCardNumber;
    inputFile>>input_memberName>>input_idCardNumber>>input_id>>input_pw;  // 회원의 기본정보입력

    signUp->getEssentailInfo(input_memberName, input_idCardNumber, input_id, input_pw); // 회원의 기본 정보를 컨트롤 클래스로 넘김
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
    outputFile<<"> "<<memberName<<" "<<memberIDCardNumber<<" "<<memberID<<" "<<memberPW<<endl<<endl;
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
    SignUpUI *signUpUI = new SignUpUI;
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
    SignUpUI *signUpUI = new SignUpUI;
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
void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
{
    bool signupPossible = true; //회원가입 가능하면 true 아니면 false

    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);

        if (id==input_id)    // 벡터에 입력한 id가 존재하면 id 중복이 안되므로
        {
            signupPossible = false; // 가입이 불가능하다.
        }
    }
    
    if (signupPossible)  // 회원가입이 가능하면 (=겹치는 아이디없으면) 회원가입한다.
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

/*
Function : void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
Description: 이 함수는 회원탈퇴 버튼을 누르면 회원탈퇴를 진행하는 함수입니다.
Parameters : DeleteMyAccount *deleteMyAccount - DeleteMyAccount 클래스의 객체의 주소를 가리키는 포인터
Return Value : void
Created: 2022/5/26 6:00 am
Author: 최준수
*/
void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
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
    outputFile<<"> "<<curMemberID<<endl<<endl;
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
    DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
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
Function : void doTask()
Description: 이 함수는 입력받은 메뉴에 따라 해당 메뉴의 작업을 하는 함수입니다.
Parameters : void
Return Value : void
Created: 2022/5/25 : 3:00 pm
Author: 최준수
*/
void doTask(){
    if (inputFile.is_open())    //파일이 열려있는지 확인
    {
        while (!inputFile.eof())    //파일의 끝까지 읽는것을 반복
        {
            string str;

            while (1)
            {
                int menu1,menu2;
                inputFile>>menu1>>menu2;    // 파일로부터 메뉴2개 를 입력받음

                if (menu1 == 1 && menu2 == 1)
                {
                    outputFile<<"1.1. 회원가입"<<endl;

                    if (loginState)  // 현재 로그인중이라면 회원가입을 할 수 없다.
                    {
                        outputFile<<"로그아웃 후 회원가입을 진행해주세요"<<endl<<endl;    // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
                    }
                    else    // 로그아웃 상태에서만 회원가입을 할 수 있다.
                    {
                        SignUp *signUp = new SignUp;
                    }
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile<<"1.2. 회원탈퇴"<<endl;

                    DeleteMyAccount *deleteMyAccount = new DeleteMyAccount;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile<<"2.1. 로그인"<<endl;

                    if (loginState)  // 로그인 상태에서는 로그인을 할 수 없다.
                    {
                        outputFile<<"로그인 할 수없습니다 로그아웃 후 사용해주세요"<<endl<<endl;  // 디버그시 확인하기위한 예외처리 최종본에서 지워도 되는코드
                    }
                    else // 로그아웃 상태에서만 로그인 할 수 있다.
                    {
                        Login *login = new Login;
                    }
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile<<"2.2. 로그아웃"<<endl;

                    Logout *logout = new Logout;

                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile<<"3.1. 판매 의류 등록"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile<<"3.2. 등록 상품 조회"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 3 && menu2 == 3)
                {
                    outputFile<<"3.3. 판매 완료 상품 조회"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile<<"4.1. 상품 정보 검색"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile<<"4.2. 상품 구매"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile<<"4.3. 상품 구매 내역 조회"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile<<"4.4. 상품 구매만족도 평가"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile<<"5.1. 판매 상품 통계"<<endl;
                    /*
                        구현부
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 6 && menu2 ==1)
                {
                    outputFile<<"6.1. 종료"<<endl;
                    return ; //doTask 함수종료
                }
                getline(inputFile,str);
            }
        }
    }
}

int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}