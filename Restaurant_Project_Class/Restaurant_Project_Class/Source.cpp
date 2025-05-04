#include"List.h"

class Admin;
class User {
	string username;
	string password;
	string phone_number;
	string mail;
	float wallet;
	int age;
public:
	User() {
		this->username = "";
		this->password = "";
		this->phone_number = "";
		this->mail = "";
		this->wallet = 0.0;
		this->age = 0;
	}
	User(string username, string password, string phone_number, string mail, float wallet, int age) {
		SetUsername(username);
		SetPassword(password);
		SetPhoneNumber(phone_number);
		SetMail(mail);
		SetWallet(wallet);
		SetAge(age);
	}

	string GetUsername() const {
		return username;
	}
	string GetPassword() const {
		return password;
	}
	string GetPhoneNumber() const {
		return phone_number;
	}
	string GetMail() const {
		return mail;
	}
	float GetWallet() {
		return wallet;
	}
	int GetAge() const {
		return age;
	}

	void SetUsername(string username) {
		if (username.length() >= 3) {
			this->username = username;
		}
		else {
			throw string("Username is short...");
		}
	}

	void SetPassword(string password) {
		if (password.length() >= 8) {
			this->password = password;
		}
		else {
			throw string("Password is short...");
		}
	}
	//055 123 12 32
	void SetPhoneNumber(string phone_number) {
		if (phone_number.length() == 14) {
			this->phone_number = phone_number;
		}
		else {
			throw string("Phone number must be 10 digits...");
		}
	}
	void SetMail(string mail) {
		int len = mail.length();
		if (mail.substr(len - 10, 10) == "@gmail.com") {
			this->mail = mail;
		}
		else {
			throw string("Mail is wrong...");
		}
	}
	void SetWallet(float wallet) {
		if (wallet >= 0) {
			this->wallet = wallet;
		}
		else {
			throw string("Wallet can not be less than 0...");
		}
	}
	void SetAge(int age) {
		if (age >= 15) {
			this->age = age;
		}
		else {
			throw string("Age is lower than 15...");
		}
	}


};


class UserManager {
	DoubleLinkedList<User> users;
	static int count;
public:
	UserManager() {
		count++;
	}

	void SignUp(string username, string password, string phone_number, string mail, int age) {
		int index = SearchUser(username, mail);
		if (index != -1) {
			throw string("This username or mail already exists....");
		}
		else {
			float wallet = 0;
			User* user = new User(username, password, phone_number, mail, wallet, age);
			users.AddEnd(*user);
		}
	}
	void SignIn(string username, string password, string mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			cout << "Welcome" << endl;
		}
	}
	void ChangePassword(string username, string old_password, string new_password, string mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			if (users[index].GetPassword() == old_password) {
				users[index].SetPassword(new_password);
			}
			else {
				throw string("Password is wrong...");
			}
		}
	}
	void ChangeMail(string username, string old_password, string mail, string new_mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			if (users[index].GetPassword() == old_password) {
				users[index].SetMail(new_mail);
			}
			else {
				throw string("Password is wrong...");
			}
		}
	}
	void ChangePhoneNumber(string username, string password, string new_phone_number, string mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			if (users[index].GetPassword() == password) {
				users[index].SetPhoneNumber(new_phone_number);
			}
			else {
				throw string("Wrong password...");
			}
		}
	}
	void ChangeWallet(string username, string password, float wallet, string mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			if (users[index].GetPassword() == password) {
				users[index].SetWallet(wallet);
			}
			else {
				throw string("Wrong password...");
			}
		}
	}

	void DeleteUser(string username, string password, string mail) {
		int index = SearchUser(username, mail);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			if (users[index].GetPassword() == password) {
				users.DeleteIndex(index);
			}
			else {
				throw string("Wrong password...");
			}
		}
	}

	int SearchUser(string username, string mail) {
		for (size_t i = 0; i < users.Size(); i++)
		{
			if (users[i].GetUsername() == username || users[i].GetMail() == mail) {
				return i;
			}
		}
		return -1;
	}
	void ShowAllUsers() {//admin de olacaq deye melumatlar gorunur
		for (size_t i = 0; i < users.Size(); i++)
		{
			cout << "Name: " << users[i].GetUsername() << endl;
			cout << "Password: " << users[i].GetPassword() << endl;
			cout << "Phone number: " << users[i].GetPhoneNumber() << endl;
			cout << "Mail: " << users[i].GetMail() << endl;
			cout << "Age: " << users[i].GetAge() << endl;
			cout << "Wallet: " << users[i].GetWallet() << endl;
			cout << "_____________________________________________" << endl;
		}
	}

	~UserManager() {
		count--;
	}
};
int UserManager::count = 0;

class Ingridient {
	string name;
	float pricePerGram;
	float weightGram;


public:
	Ingridient() {};
	Ingridient(string name, float pricePerGram, float weightGram) {
		this->name = name;
		this->pricePerGram = pricePerGram;
		this->weightGram = weightGram;
	}
	string GetName() {
		return this->name;
	}
	float GetPricePerGram() {
		return pricePerGram;
	}

	int GetWeightGram() {
		return this->weightGram;
	}
	float GetTotalPrice() {
		return pricePerGram * weightGram;
	}
	void SetName(string name) {
		if (name.length() >= 2) {
			this->name = name;
		}
		else {
			throw string("Ingiridient name is short...");
		}
	}
	void SetPricePerGram(float pricePerGram) {
		if (pricePerGram >= 0) {
			this->pricePerGram = pricePerGram;
		}
		else {
			throw string("Ingiridient price can not be less than zero ...");
		}
	}
	/*void SetTotalPrice(float totalPrice) {
		if (totalPrice > 0) {
			this->totalPrice = totalPrice;
		}
		else {
			throw string("Total price can not be less than zero ...");
		}
	}*/
	void SetWeightGram(int weightGram) {
		if (weightGram >= 0) {
			this->weightGram = weightGram;
		}
		else {
			throw string("Ingiridient count can not be less than zero...");
		}
	}

};

class IngridientQuantity {
	string name;
	float totalKG;
public:
	IngridientQuantity() {};
	IngridientQuantity(string name, float totalKG) {
		this->name = name;
		this->totalKG = totalKG;
	}
	string GetIngridientName() {
		return name;
	}
	float GetTotalKG() {
		return totalKG;
	}
	void SetTotalKG(float kg) {
		if (kg > 0) {
			totalKG = kg;
		}
		else {
			throw string("Weight can not be less than zero...");
		}
	}


};

class Food {
	DoubleLinkedList<Ingridient> ingridients;
	string name;
	float price;
public:
	Food() {};
	Food(DoubleLinkedList<Ingridient>& ingridients, string name) {
		float price = 0;
		for (size_t i = 0; i < ingridients.Size(); i++)
		{
			price += ingridients[i].GetTotalPrice();
		}
		this->ingridients = ingridients;
		this->name = name;
		this->price = price;
	}
	string GetName() {
		return name;
	}
	float GetPrice() {
		return price;
	}
	DoubleLinkedList<Ingridient> GetIngridients() {
		return ingridients;
	}
	void SetName(string name) {
		if (name.length() >= 2) {
			this->name = name;
		}
		else {
			throw string("Food name must consist of at least 2 symbols...");
		}
	}
	void SetIngridients(DoubleLinkedList<Ingridient>& ingridients) {
		if (ingridients.Size() != 0) {
			this->ingridients = ingridients;
			float price = 0;
			for (size_t i = 0; i < ingridients.Size(); i++)
			{
				price += ingridients[i].GetTotalPrice();
			}
			this->price = price;

		}
		else {
			throw string("At least 1 ingridient must be setted...");
		}
	}
	void SetPrice(float price) {
		if (price >= 0) {
			this->price = price;
		}
		else {
			throw string("Food price can not be less than zero...");
		}
	}
	void ShowIngridients() {
		cout << "Ingridients: ";
		for (size_t i = 0; i < ingridients.Size(); i++)
		{

			cout << ingridients[i].GetName();
			if (i != ingridients.Size() - 1) {
				cout << ", ";
			}
		}
	}
};


class Restaurant {
	DoubleLinkedList<Food>menu;
	DoubleLinkedList<IngridientQuantity>stock;
	string name;
	float wallet;
	static int count;
public:

	Restaurant() {
		count++;
	}

	int SearchFood(string name) {
		for (size_t i = 0; i < menu.Size(); i++)
		{
			if (menu[i].GetName() == name) {
				return i;
			}
		}
		return -1;
	}

	int SearchInStock(string name) {
		for (size_t i = 0; i < stock.Size(); i++)
		{
			if (stock[i].GetIngridientName() == name) {
				return i;
			}
		}
		return -1;
	}

	void AddFood(DoubleLinkedList<Ingridient>& ingridients, string name) {
		int index = SearchFood(name);
		if (index != -1) {
			throw string("This food already exists in menu....");
		}
		else {
			Food* food = new Food(ingridients, name);
			menu.AddEnd(*food);
		}
	}

	void ChangeName(string name, string new_name) {
		int index = SearchFood(name);
		if (index == -1) {
			cout << "This food not found.." << endl;
		}
		else {
			menu[index].SetName(new_name);
		}
	}

	void ChangeIngridients(DoubleLinkedList<Ingridient>& new_ingridients, string name) {
		int index = SearchFood(name);
		if (index == -1) {
			cout << "This food not found.." << endl;
		}
		else {
			menu[index].SetIngridients(new_ingridients);
		}
	}

	void ChangePrice(string name, float price) {
		int index = SearchFood(name);
		if (index == -1) {
			cout << "This food not found.." << endl;
		}
		else {
			menu[index].SetPrice(price);
		}
	}

	void DeleteFood(string name) {
		int index = SearchFood(name);
		if (index == -1) {
			cout << "This food not found.." << endl;
		}
		else {
			menu.DeleteIndex(index);
		}
	}

	void ShowAllFoods() {
		if (menu.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		for (size_t i = 0; i < menu.Size(); i++)
		{
			cout << "Name: " << menu[i].GetName() << endl;
			menu[i].ShowIngridients();
			cout << endl;
			cout << "Price: " << menu[i].GetPrice() << endl;
			cout << "_____________________________________________" << endl;
		}
	}

	void AddIngridientToStock(string name, float kg) {
		IngridientQuantity ingridientQuantity(name, kg);
		stock.AddEnd(ingridientQuantity);
	}

	void ChangeIngridientQuantity(string name, float kg) {
		int index = SearchInStock(name);
		stock[index].SetTotalKG(kg);
	}

	void ShowStock() {
		for (size_t i = 0; i < stock.Size(); i++)
		{
			cout << "Name: " << stock[i].GetIngridientName() << endl;
			cout << "Weight: " << stock[i].GetTotalKG() << " KG" << endl;
			cout << "________________________________________" << endl;

		}
	}
	~Restaurant() {
		count--;
	}
};
int Restaurant::count = 0;


class Admin {
	string username;
	string password;
public:
	//user edit
	UserManager userManager;
	Restaurant menu;
	Admin() {};
	void AddUser(string username, string password, string phone_number, string mail, int age) {
		userManager.SignUp(username, password, phone_number, mail, age);
	}
	void DeleteUser(string username, string password, string mail) {
		userManager.DeleteUser(username, password, mail);
	}
	void ChangeUserPassword(string username, string password, string new_password, string mail) {
		userManager.ChangePassword(username, password, new_password, mail);
	}
	void ChangeUserMail(string username, string password, string mail, string new_mail) {
		userManager.ChangeMail(username, password, mail, new_mail);
	}
	void ChangeUserWallet(string username, string password, string mail, float wallet) {
		userManager.ChangeWallet(username, password, wallet, mail);
	}
	void ShowAllUsers() {
		userManager.ShowAllUsers();
	}

	//food edit

	void AddFood(DoubleLinkedList<Ingridient>& ingridients, string name) {
		menu.AddFood(ingridients, name);
	}
	void DeleteFood(string name) {
		menu.DeleteFood(name);
	}
	void ChangeFoodName(string name, string new_name) {
		menu.ChangeName(name, new_name);
	}
	void ChangeIngridients(DoubleLinkedList<Ingridient>& new_ingridients, string name) {
		menu.ChangeIngridients(new_ingridients, name);
	}
	void ChangeTotalPrice(string name, float new_price) {
		menu.ChangePrice(name, new_price);
	}
	void ShowAllFoods() {
		menu.ShowAllFoods();
	}


};

void main() {
	Admin admin;
	//admin.AddUser("Burhan", "burhan123", "+9940773214447", "burhan@gmail.com", 19);
	//admin.AddUser("Mahmud", "mahmud123", "+9940509871242", "mahmud@gmail.com", 21);
	//admin.DeleteUser("Mahmud", "mahmud123", "mahmud@gmail.com");
	////admin.ShowAllUsers();

	Restaurant restaurant;

	DoubleLinkedList<Ingridient> ingridients;
	DoubleLinkedList<Ingridient> ingridients2;
	ingridients.AddEnd(Ingridient("Tomato", 0.01, 500));
	ingridients.AddEnd(Ingridient("Potato", 0.02, 300));
	ingridients2.AddEnd(Ingridient("Cucumber ", 0.01, 300));
	ingridients2.AddEnd(Ingridient("Chicken", 0.03, 300));
	restaurant.AddFood(ingridients, "Pasta");
	restaurant.AddFood(ingridients2, "Chesar");
	/*restaurant.ChangeIngridients(ingridients, "Chesar");*/
	restaurant.ChangePrice("Chesar", 123);
	restaurant.AddIngridientToStock("Tomato", 15);
	restaurant.AddIngridientToStock("Potato", 20);
	restaurant.ShowStock();



}

