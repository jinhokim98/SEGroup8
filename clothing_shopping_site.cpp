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

class SignUp
{
private:
    
public:
    SignUp();
    void ProceedSignUp();
    void getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw);
};

class SignUpUI
{
private:
    
public:
    void PushSignUpButton(SignUp *signUp);
    void ShowEssentialInfoInputInterface();
    void InputEssentialInfo(SignUp *signUp);
    void ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW);
};

class DeleteMyAccount
{
private:
    
public:
    DeleteMyAccount();
    void DeleteAccount();

};

class DeleteMyAccountUI
{
private:
    
public:
    void DeleteAccountButton(DeleteMyAccount *deleteMyAccount);
    void ShowCompleteDeleteAccount(string id);
};

class Login
{
private:
    
public:
    Login();
    bool IDPWinputed(string input_id, string input_pw);
};

class LoginUI
{
private:
    
public:
    bool inputIDPW(Login* login);
    void ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW);
};

class Logout
{
private:
    
public:
    Logout();
    void DoLogout();
};

class LogoutUI
{
private:
    
public:
    void PushLogoutButton(Logout *logout);
    void ShowCompleteLogoutMessage();
};

class Member
{
private:
    string id, pw, memberName, idCardNumber;

public:
	string getID(){return id;}  // ��ü�� id�� get�ϴ� �Լ�
	string getPW(){return pw;}  // ��ü�� pw�� get�ϴ� �Լ�
	string getMemberName(){return memberName;}  // ��ü�� �̸��� get�ϴ� �Լ�
	string getIDCardNumber(){return idCardNumber;}  // ��ü�� �ֹι�ȣ�� get�ϴ� �Լ�
	Member* address_of_object(){return this;}   // �� ��ü�� �ּҸ� get�ϴ� �Լ�
    int checkIDPW(string input_id,string input_pw);

	Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //������
	~Member(); //�ı���
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //������ ù���� id , �ι�° ���� pw , ����° ���� �ش簳ü�� ������ ����
Member* curLoginMember; // ���� �α������� ȸ���� ������ �������� ����
bool loginState = false; // ���� �α������̸� true �α׾ƿ����̸� false ������ �������� ����

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
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 4 && menu2 == 1)
                {
                    outputFile<<"4.1. ��ǰ ���� �˻�"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 4 && menu2 == 2)
                {
                    outputFile<<"4.2. ��ǰ ����"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 4 && menu2 == 3)
                {
                    outputFile<<"4.3. ��ǰ ���� ���� ��ȸ"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if(menu1 == 4 && menu2 == 4)
                {
                    outputFile<<"4.4. ��ǰ ���Ÿ����� ��"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
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

int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}