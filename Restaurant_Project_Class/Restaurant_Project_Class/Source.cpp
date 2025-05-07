#include"List.h"

string toUpperCase(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}
string toLowerCase(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

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
	void SetWeightGram(int weightGram) {
		if (weightGram >= 0) {
			this->weightGram = weightGram;
		}
		else {
			throw string("Ingiridient count can not be less than zero...");
		}
	}

};
class Food {
	DoubleLinkedList<Ingridient> ingridients;
	string name;
	string description;
	float price;
public:
	Food() {};
	Food(DoubleLinkedList<Ingridient>& ingridients, string name, string description) {
		float price = 0;
		for (size_t i = 0; i < ingridients.Size(); i++)
		{
			price += ingridients[i].GetTotalPrice();
		}
		this->ingridients = ingridients;
		this->name = name;
		this->description = description;
		this->price = price;
	}
	string GetName() {
		return name;
	}
	string GetDescription() {
		return description;
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

			cout << toLowerCase(ingridients[i].GetName());
			if (i != ingridients.Size() - 1) {
				cout << ", ";
			}
		}
	}

	void SetDescription(string description) {
		int count = 0;
		for (size_t i = 0; i < description.length(); i++)
		{
			if (description[i] == ' ') {
				count++;
			}
		}
		if (count >= 4) {
			this->description = description;
		}
		else {
			throw string("Description must be at least 5 words...");
		}
	}





};
class User {
	string username;
	string password;
	string phone_number;
	string mail;

	int age;


public:
	DoubleLinkedList<Food>history;
	DoubleLinkedList<Food>card;
	User() {
		this->username = "";
		this->password = "";
		this->phone_number = "";
		this->mail = "";

		this->age = 0;

	}
	User(string username, string password, string phone_number, string mail, int age) {
		SetUsername(username);
		SetPassword(password);
		SetPhoneNumber(phone_number);
		SetMail(mail);

		SetAge(age);
	}
	void AddToCard(Food food) {
		card.AddEnd(food);
	}

	void AddToHistory(Food food) {
		this->history.AddEnd(food);

	}
	void AddToHistoryList(DoubleLinkedList<Food> food) {

		for (size_t i = 0; i < food.Size(); i++)
		{
			this->history.AddEnd(food[i]);
		}
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

	void SetPhoneNumber(string phone_number) {
		if (phone_number.length() == 14) {
			this->phone_number = phone_number;
		}
		else {
			throw string("Phone number must be 14 digits...");
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

	void SetAge(int age) {
		if (age >= 15) {
			this->age = age;
		}
		else {
			throw string("Age is lower than 15...");
		}
	}


	void ShowHistory() {
		if (history.Size() == 0) {
			cout << "You do not have any order yet...";
		}
		for (size_t i = 0; i < history.Size(); i++)
		{
			cout << "Name: " << history[i].GetName() << " - " << history[i].GetPrice() << endl;
			cout << endl;
			cout << endl;
		}
	}
	void ShowCard() {
		float total_price = 0;
		for (size_t i = 0; i < card.Size(); i++)
		{
			total_price += card[i].GetPrice();
			cout << "Name: " << card[i].GetName() << " - " << card[i].GetPrice();
			cout << endl;

		}
		cout << endl;
		cout << endl;
		cout << "Total price: " << total_price << endl;
		cout << endl;
		cout << endl;
	}
	float GetTotalPriceCard() {
		float total_price = 0;
		for (size_t i = 0; i < card.Size(); i++)
		{
			total_price += card[i].GetPrice();
		}
		return total_price;
	}

	void WriteToFileHistory(const string& username, DoubleLinkedList<Food>& history, const string& filename = "history.txt") {
		fstream fs(filename, ios::app);
		if (!fs.is_open()) {
			cerr << "Error: Unable to open file " << filename << endl;
			throw string("File couldn't open!");
		}

		if (history.Size() == 0) {
			cerr << "Error: No history to write to file." << endl;
			fs.close();
			return;
		}

		fs << "[User: " << username << "]\n";

		for (size_t i = 0; i < history.Size(); i++) {
			Food food = history[i];
			fs << food.GetName() << "#"
				<< food.GetPrice() << "#"
				<< food.GetDescription() << "#";

			DoubleLinkedList<Ingridient> ingredients = food.GetIngridients();
			for (size_t j = 0; j < ingredients.Size(); j++) {
				Ingridient ingredient = ingredients[j];
				fs << ingredient.GetName() << ":"
					<< ingredient.GetPricePerGram() << ":"
					<< ingredient.GetWeightGram();
				if (j != ingredients.Size() - 1) {
					fs << ",";
				}
			}
			fs << "\n";
		}

		fs << "\n";
		fs.close();
	}

	void ReadFromFileHistory(DoubleLinkedList<Food>& history, const string& filename = "history.txt") {
		fstream fs(filename, ios::in);
		if (!fs.is_open()) {
			cerr << "Error: Unable to open file " << filename << endl;
			throw string("File couldn't open!");
		}

		if (fs.peek() == std::ifstream::traits_type::eof()) {
			cerr << "Error: File is empty." << endl;
			fs.close();
			return;
		}

		string row;
		while (getline(fs, row)) {

			stringstream ss(row);
			string name, priceStr, description, ingredientsStr;

			try {
				getline(ss, name, '#');
				getline(ss, priceStr, '#');
				getline(ss, description, '#');
				getline(ss, ingredientsStr, '#');

				float price = stof(priceStr);
				DoubleLinkedList<Ingridient> ingredients;
				stringstream ingredientsStream(ingredientsStr);
				string ingredientData;

				while (getline(ingredientsStream, ingredientData, ',')) {
					stringstream ingredientStream(ingredientData);
					string ingredientName, pricePerGramStr, weightGramStr;

					getline(ingredientStream, ingredientName, ':');
					getline(ingredientStream, pricePerGramStr, ':');
					getline(ingredientStream, weightGramStr, ':');

					float pricePerGram = stof(pricePerGramStr);
					float weightGram = stof(weightGramStr);

					Ingridient ingredient(ingredientName, pricePerGram, weightGram);
					ingredients.AddEnd(ingredient);

				}

				Food food(ingredients, name, description);
				food.SetPrice(price);
				history.AddEnd(food);

				cout << endl;
				cout << "Food: " << food.GetName() << ", Price: " << food.GetPrice()
					<< ", Description: " << food.GetDescription() << endl;
				cout << "______________________________________________________" << endl;
				cout << endl;
				cout << endl;
				
			}
			catch (const std::exception& e) {

				continue;
			}
		}

		fs.close();
	}

	void ReadFromFileHistoryOneUser(const string& username, DoubleLinkedList<Food>& history, const string& filename = "history.txt") {
		fstream fs(filename, ios::in);
		if (!fs.is_open()) {
			cerr << "Error: Unable to open file " << filename << endl;
			throw string("File couldn't open!");
		}

		string row;
		bool userFound = false;

		while (getline(fs, row)) {
			if (row.rfind("[User:", 0) == 0) {

				string currentUser = row.substr(7, row.length() - 8);
				userFound = (currentUser == username);
				continue;
			}

			if (userFound && !row.empty()) {
				stringstream ss(row);
				string name, priceStr, description, ingredientsStr;

				getline(ss, name, '#');
				getline(ss, priceStr, '#');
				getline(ss, description, '#');
				getline(ss, ingredientsStr, '#');

				float price = stof(priceStr);
				DoubleLinkedList<Ingridient> ingredients;

				stringstream ingredientsStream(ingredientsStr);
				string ingredientData;

				while (getline(ingredientsStream, ingredientData, ',')) {
					stringstream ingredientStream(ingredientData);
					string ingredientName, pricePerGramStr, weightGramStr;

					getline(ingredientStream, ingredientName, ':');
					getline(ingredientStream, pricePerGramStr, ':');
					getline(ingredientStream, weightGramStr, ':');

					float pricePerGram = stof(pricePerGramStr);
					float weightGram = stof(weightGramStr);

					Ingridient ingredient(ingredientName, pricePerGram, weightGram);
					ingredients.AddEnd(ingredient);
				}

				Food food(ingredients, name, description);
				food.SetPrice(price);
				history.AddEnd(food);
			}
			else if (userFound && row.empty()) {
				break; // Stop if we hit empty line after current user's data
			}
		}

		fs.close();
	}

};
class Admin {
public:
	DoubleLinkedList<User> users;

	bool SignUp(const string& username, const string& password, const string& phone_number, const string& mail, const int& age) {
		int index = SearchUser(username);
		if (index == -1) {
			User user(username, password, phone_number, mail, age);
			users.AddEnd(user);
			return true;
		}
		else {
			throw string("User already exists...");
			return false;
		}
	}

	bool SignIn(const string& username, const string& password) {
		int index = SearchUser(username);
		if (index != -1) {
			if (users[index].GetPassword() == password) {
				return true;
			}
			else {
				throw string("Password is wrong...");
			}
		}
		else {
			throw string("Username is wrong...");
		}
	}

	void ChangePassword(const string& username, const string& old_password, const string& new_password) {
		int index = SearchUser(username);
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
	void ChangeMail(const string& username, const string& old_password, const string& new_mail) {
		int index = SearchUser(username);
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
	void ChangePhoneNumber(const string& username, const string& password, const string& new_phone_number) {
		int index = SearchUser(username);
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


	void DeleteUser(const string& username) {
		int index = SearchUser(username);
		if (index == -1) {
			cout << "This user not found.." << endl;
		}
		else {
			users.DeleteIndex(index);
		}
	}

	int SearchUser(const string& username) {
		for (size_t i = 0; i < users.Size(); i++) {
			if (users[i].GetUsername() == username) {
				return static_cast<int>(i);
			}
		}
		return -1;
	}
	User& SearchUserReturnUser(const string& username) {
		for (size_t i = 0; i < users.Size(); i++) {
			if (users[i].GetUsername() == username) {
				return users[i];
			}
		};
	}

	void ShowAllUsers() {//admin de olacaq deye melumatlar gorunur
		if (users.Size() != 0) {
			for (size_t i = 0; i < users.Size(); i++)
			{
				cout << "Name: " << users[i].GetUsername() << endl;
				cout << "Password: " << users[i].GetPassword() << endl;
				cout << "Phone number: " << users[i].GetPhoneNumber() << endl;
				cout << "Mail: " << users[i].GetMail() << endl;
				cout << "Age: " << users[i].GetAge() << endl;

				cout << "___________________________________________" << endl;
			}
		}
		else {
			cout << "You do not have any user yet..." << endl;
		}
	}
	void ShowOneUser(string& name) {
		system("cls");
		int i = SearchUser(name);
		if (users.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		else {
			cout << "Name: " << users[i].GetUsername() << endl;
			cout << "Password: " << users[i].GetPassword() << endl;
			cout << "Phone number: " << users[i].GetPhoneNumber() << endl;
			cout << "Mail: " << users[i].GetMail() << endl;
			cout << "Age: " << users[i].GetAge() << endl;

			cout << "___________________________________________" << endl;

		}
	}



	Admin() {};
	void WriteToFile(DoubleLinkedList<User>& users, const string filename = "users.txt") {
		fstream fs(filename, ios::out);
		if (!fs.is_open()) {
			cerr << "Error: Unable to open file " << filename << endl;
			throw string("File couldn't open!");
		}

		if (users.Size() == 0) {
			cerr << "Error: No users to write to file." << endl;
			fs.close();
			return;
		}

		for (size_t i = 0; i < users.Size(); i++) {
			User user = users[i];
			fs << user.GetUsername() << "#"
				<< user.GetPassword() << "#"
				<< user.GetPhoneNumber() << "#"
				<< user.GetMail() << "#"
				<< user.GetAge() << "#";

		}

		fs.close();

	}

	void ReadFromFile(DoubleLinkedList<User>& users, const string& filename = "users.txt") {
		fstream fs(filename, ios::in);
		if (fs.is_open()) {
			string row;
			while (getline(fs, row)) {
				stringstream ss(row);
				string username, password, phone, mail, ageStr;

				getline(ss, username, '#');
				getline(ss, password, '#');
				getline(ss, phone, '#');
				getline(ss, mail, '#');
				getline(ss, ageStr, '#');

				int age = stoi(ageStr);


				User user(username, password, phone, mail, age);


				users.AddEnd(user);
			}
			fs.close();
		}
		else {
			throw string("File couldn't open!");
		}
	}
};
class Restaurant {
	Admin admin;
	string name;
	float wallet;
	static int count;
public:
	DoubleLinkedList<Food>menu;
	DoubleLinkedList<Ingridient>stock;
	Restaurant() : wallet(0) {
		count++;
	}


	int SearchFood(string name) {
		for (size_t i = 0; i < menu.Size(); i++)
		{
			if (toUpperCase(menu[i].GetName()) == toUpperCase(name)) {
				return i;
			}
		}
		return -1;
	}
	int SearchInStock(string name) {
		for (size_t i = 0; i < stock.Size(); i++)
		{
			if (toUpperCase(stock[i].GetName()) == toUpperCase(name)) {
				return i;
			}
		}
		return -1;
	}
	bool IsEnough(string name, float weight) {
		int index = SearchInStock(name);
		if (index == -1) {
			return false;
		}
		else
		{
			if (stock[index].GetWeightGram() >= weight) {
				return true;
			}
			else {
				false;
			}
		}
	}
	string GetIName(int index) {
		return stock[index].GetName();
	}
	float GetIPricePerGram(int index) {
		return stock[index].GetPricePerGram();
	}
	float GetRestaurantsWallet() {
		return wallet;
	}
	void AddFood(DoubleLinkedList<Ingridient>& ingridients, string name, string description) {
		int index = SearchFood(name);
		if (index != -1) {
			throw string("This food already exists in menu....");
		}
		else {
			Food food(ingridients, name, description);
			menu.AddEnd(food);
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
		system("cls");
		if (menu.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		else {
			for (size_t i = 0; i < menu.Size(); i++)
			{
				cout << i + 1 << "." << "Name: " << menu[i].GetName() << endl;
				menu[i].ShowIngridients();
				cout << endl;
				cout << "Description: " << menu[i].GetDescription() << endl;
				cout << "Price: " << menu[i].GetPrice() << endl;
				cout << "___________________________________________" << endl;
			}
		}
	}
	void ShowAllForUser() {
		system("cls");
		if (menu.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		else {
			for (size_t i = 0; i < menu.Size(); i++)
			{
				cout << i + 1 << "." << "Name: " << menu[i].GetName() << endl;
				cout << "Price: " << menu[i].GetPrice() << endl;
				cout << "___________________________________________" << endl;
			}
		}
	}
	void ShowOneFood(const string& name) {
		system("cls");
		int index = SearchFood(name);
		if (menu.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		else if (index == -1) {
			cout << "Food not found" << endl;
		}
		else {
			cout << "Name: " << menu[index].GetName() << endl;
			menu[index].ShowIngridients();
			cout << endl;
			cout << "Description: " << menu[index].GetDescription() << endl;
			cout << "Price: " << menu[index].GetPrice() << endl;
			cout << "___________________________________________" << endl;
		}
	}
	Food ReturnOneFood(const string& name) {

		int index = SearchFood(name);
		if (menu.Size() == 0) {
			cout << "Menu is empty..." << endl;
		}
		else {
			return menu[index];
		}
	}
	void IncreaseWallet(string cardNumber, int month, int year, string cvv, float new_money) {
		if (cardNumber.length() == 16 && cvv.length() == 3 && (month > 0 && month < 13)) {
			this->wallet += new_money;
		}
		else {
			throw string("Wrong card details...");
		}
	}
	void AddIngridientToStock(string name, float pricePerGram, float totalWeight) {
		int index = SearchInStock(name);
		if (index == -1) {
			int spent = pricePerGram * totalWeight;
			if (wallet >= spent) {
				Ingridient ingridient(name, pricePerGram, totalWeight);
				stock.AddEnd(ingridient);
				wallet -= spent;
			}
			else {
				throw string("Not enough money...");
			}
		}
		else {
			throw string("Ingridient already exists in stock");///cagirdigin yerde catch de deki cekisin artir?
		}
	}
	void IncreaseWeight(string name, float Gram) {
		int index = SearchInStock(name);
		float spent;
		if (index != -1) {
			spent = Gram * stock[index].GetPricePerGram();
			if (wallet >= spent) {
				wallet -= spent;
				float new_gram = stock[index].GetWeightGram() + Gram;
				stock[index].SetWeightGram(new_gram);
			}
			else {
				throw string("Not enough money in wallet...");
			}
		}
		else {
			throw string("Ingridinet can not be found in stock...");
		}
	}
	void ShowWallet() {
		cout << "Budget: " << wallet << endl;
	}
	void ShowStock() {
		if (stock.Size() != 0) {
			for (size_t i = 0; i < stock.Size(); i++)
			{
				cout << "Name: " << toLowerCase(stock[i].GetName()) << endl;
				cout << "Price per gram: " << stock[i].GetPricePerGram() << endl;
				cout << "Weight: " << stock[i].GetWeightGram() << " gr" << endl;
				cout << "______________________________________" << endl;

			}
		}
		else {
			cout << "Stock is empty..." << endl;
		}
	}
	~Restaurant() {
		count--;
	}
	Ingridient& GetFromStock(int index) {
		return stock[index];
	}
	void DecreaseIngridientWeight(int index, float weight) {
		stock[index].SetWeightGram(stock[index].GetWeightGram() - weight);
	}
	void ChangeUserPassword(string username, string password, string new_password) {
		admin.ChangePassword(username, password, new_password);
	}
	void ChangeUserMail(string username, string password, string new_mail) {
		admin.ChangeMail(username, password, new_mail);
	}

	void WriteToFileFood(DoubleLinkedList<Food>& menu, const string filename = "menu.txt") {
		fstream fs(filename, ios::out);
		if (!fs.is_open()) {

			throw string("File couldn't open!");
		}
		if (menu.Size() == 0) {

			fs.close();
			return;
		}
		for (size_t i = 0; i < menu.Size(); i++) {
			Food food = menu[i];

			fs << food.GetName() << "#"
				<< food.GetPrice() << "#"
				<< food.GetDescription() << "#";
			DoubleLinkedList<Ingridient> ingredients = food.GetIngridients();
			for (size_t j = 0; j < ingredients.Size(); j++) {
				Ingridient ingredient = ingredients[j];
				fs << ingredient.GetName() << ":" << ingredient.GetPricePerGram() << ":" << ingredient.GetWeightGram();
				if (j != ingredients.Size() - 1) {
					fs << ",";
				}
			}
			fs << "\n";
		}
		fs.close();

	}
	void ReadFromFileFood(DoubleLinkedList<Food>& menu, const string& filename = "menu.txt") {
		fstream fs(filename, ios::in);
		if (!fs.is_open()) {
			throw string("File couldn't open!");
		}
		string row;
		while (getline(fs, row)) {
			stringstream ss(row);
			string name, priceStr, description, ingredientsStr;
			getline(ss, name, '#');
			getline(ss, priceStr, '#');
			getline(ss, description, '#');
			getline(ss, ingredientsStr, '#');
			float price = stof(priceStr);
			DoubleLinkedList<Ingridient> ingredients;
			stringstream ingredientsStream(ingredientsStr);
			string ingredientData;
			while (getline(ingredientsStream, ingredientData, ',')) {
				stringstream ingredientStream(ingredientData);
				string ingredientName, pricePerGramStr, weightGramStr;
				getline(ingredientStream, ingredientName, ':');
				getline(ingredientStream, pricePerGramStr, ':');
				getline(ingredientStream, weightGramStr, ':');
				float pricePerGram = stof(pricePerGramStr);
				float weightGram = stof(weightGramStr);
				Ingridient ingredient(ingredientName, pricePerGram, weightGram);
				ingredients.AddEnd(ingredient);
			}
			Food food(ingredients, name, description);
			food.SetPrice(price);
			menu.AddEnd(food);
		}
		fs.close();
	}


	void WriteToFileIngridients(DoubleLinkedList<Ingridient>& ingredients, const string filename = "ingredients.txt") {
		fstream fs(filename, ios::out);
		if (!fs.is_open()) {

			throw string("File couldn't open!");
		}

		if (ingredients.Size() == 0) {

			fs.close();
			return;
		}


		for (size_t i = 0; i < ingredients.Size(); i++) {
			Ingridient ingredient = ingredients[i];
			fs << ingredient.GetName() << "#"
				<< ingredient.GetPricePerGram() << "#"
				<< ingredient.GetWeightGram() << "\n";

		}

		fs.close();

	}
	void ReadFromFileIngridients(DoubleLinkedList<Ingridient>& ingredients, const string& filename = "ingredients.txt") {
		fstream fs(filename, ios::in);
		if (!fs.is_open()) {

			throw string("File couldn't open!");
		}

		string row;
		while (getline(fs, row)) {
			stringstream ss(row);
			string name, pricePerGramStr, weightGramStr;

			getline(ss, name, '#');
			getline(ss, pricePerGramStr, '#');
			getline(ss, weightGramStr, '#');

			float pricePerGram = stof(pricePerGramStr);
			float weightGram = stof(weightGramStr);

			Ingridient ingredient(name, pricePerGram, weightGram);
			ingredients.AddEnd(ingredient);

		}

		fs.close();
	}



};
int Restaurant::count = 0;
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void main() {
	Admin admin;
	Restaurant restaurant;
	User user;


	try
	{
		admin.ReadFromFile(admin.users);
	}
	catch (string ex)
	{

		admin.WriteToFile(admin.users);
	}
	try
	{
		restaurant.ReadFromFileFood(restaurant.menu);
	}
	catch (string ex)
	{

		restaurant.WriteToFileFood(restaurant.menu);
	}
	try
	{
		restaurant.ReadFromFileIngridients(restaurant.stock);
	}
	catch (string ex)
	{

		restaurant.WriteToFileIngridients(restaurant.stock);
	}


	int choice;
	SetColor(14);
	cout << "\t\t\t\t\t ________________________" << endl;
	cout << "\t\t\t\t\t|Welcome to our restaurant!|" << endl;
	cout << "\t\t\t\t\t --------------------------" << endl;
	cout << "\t\t1.Admin                                                   2.User" << endl;
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	if (choice == 1) {
		string username, password;
		for (size_t i = 0; i < 3; i++)
		{
			cout << "Enter username: ";
			getline(cin, username);
			cout << "Enter password: ";
			getline(cin, password);
			if (username == "admin") {
				if (password == "admin") {
					system("cls");
					cout << "\t\t\t\t\t\t\tWelcome admin!\t\t\t\t\t" << __TIME__ << endl;
					i = 2;
					int choice2;
					while (true) {
						cout << "|1.Show users" << endl;
						cout << "|2.Show menu" << endl;
						cout << "|3.Show stock" << endl;
						cout << "|4.Add food" << endl;
						cout << "|5.Delete food" << endl;
						cout << "|6.Search a food" << endl;
						cout << "|7.Search a user" << endl;
						cout << "|8.Add user" << endl;
						cout << "|9.Delete user" << endl;
						cout << "|10.Add ingridient" << endl;
						cout << "|11.Increase budget" << endl;
						cout << "|12.Update meal" << endl;
						cout << "|13.Show sell history" << endl;
						cout << "|14.Show restaurant's budget" << endl;
						cout << "|15.Back to register" << endl;

						cout << "Choose: ";
						cin >> choice2;


						if (choice2 == 1) {
							system("cls");
							admin.ShowAllUsers();
						}
						else if (choice2 == 2) {
							system("cls");
							restaurant.ShowAllFoods();
						}
						else if (choice2 == 3) {
							system("cls");
							restaurant.ShowStock();
						}
						else if (choice2 == 4) {//i ingridient f food
							system("cls");
							string Iname;
							string Fname;
							string descp;
							float Iweight;
							int count;
							int index;
							cin.ignore();
							cout << "Enter name of the meal: ";
							getline(cin, Fname);
							cout << "Enter the description: ";
							getline(cin, descp);
							DoubleLinkedList<Ingridient>ingridientsFood;
							cout << "How many ingridients will be the meal consist of - ";
							cin >> count;
							cin.ignore();
							for (size_t i = 0; i < count; i++)
							{

								cout << "Enter " << i + 1 << " th ingridinent: ";
								getline(cin, Iname);
								cout << "Enter that ingridient's weight: ";
								cin >> Iweight;
								cin.ignore();
								index = restaurant.SearchInStock(Iname);
								if (index != -1) {
									if (restaurant.IsEnough(Iname, Iweight)) {
										Ingridient new_ingridient(restaurant.GetIName(index), restaurant.GetIPricePerGram(index), Iweight);
										ingridientsFood.AddEnd(new_ingridient);

									}
									else {
										cout << "You do not have in stock enough.Try less weight or you can use other ingridients." << endl;
									}
								}
								else {
									cout << "You do not have in stock.Try other ingridients." << endl;
									i--;
								}
							}
							for (size_t i = 0; i < 3; i++) {
								try
								{
									restaurant.AddFood(ingridientsFood, Fname, descp);
									restaurant.WriteToFileFood(restaurant.menu);
									cout << "Added..." << endl;
									i = 3;

								}
								catch (string ex)
								{
									cout << "Error: " << ex << endl;

								}
							}


						}
						else if (choice2 == 5) {
							system("cls");
							string name;
							cin.ignore();
							cout << "Delete food" << endl;
							cout << "Enter name: ";
							getline(cin, name);
							int index = admin.SearchUser(name);
							admin.users.DeleteIndex(index);
							admin.WriteToFile(admin.users);
							cout << "Deleted..." << endl;
						}
						else if (choice2 == 6) {
							system("cls");
							string name;
							cin.ignore();
							cout << "Seach" << endl;
							cout << "Enter name: ";
							getline(cin, name);
							restaurant.ShowOneFood(name);

						}
						else if (choice2 == 7) {
							cin.ignore();
							system("cls");
							string name;

							cout << "Search user" << endl;
							cout << "Enter name: ";
							getline(cin, name);
							admin.ShowOneUser(name);
						}
						else if (choice2 == 8) {
							bool flag;
							string username, password, phone_numebr, mail;
							int age;
							for (size_t i = 0; i < 3; i++)
							{
								system("cls");
								cin.ignore();
								cout << "Enter username: ";
								getline(cin, username);
								cout << "Enter password: ";
								getline(cin, password);
								cout << "Enter phone number: ";
								getline(cin, phone_numebr);
								cout << "Enter mail: ";
								getline(cin, mail);
								cout << "Enter age: ";
								cin >> age;
								cout << "_______________________" << endl;
								try
								{
									User user(username, password, phone_numebr, mail, age);
									admin.users.AddEnd(user);
									admin.WriteToFile(admin.users);
									system("cls");
									cout << "Added..." << endl;
								}
								catch (string ex)
								{
									system("cls");
									cout << "Error: " << ex << endl;
									i--;
								}
								break;

								if (i == 2) {
									cout << "You have reached the limit.Try later." << endl;
								}
							}
						}
						else if (choice2 == 9) {
							cin.ignore();
							system("cls");
							string name;

							cout << "Search user" << endl;
							cout << "Enter name: ";
							getline(cin, name);
							admin.DeleteUser(name);
							admin.WriteToFile(admin.users);
							cout << "Deleted" << endl;
						}
						else if (choice2 == 10) {
							cin.ignore();
							system("cls");
							string name;
							float pricePergram;
							float totalWeight;
							cout << "Search user" << endl;
							cout << "Enter name: ";
							getline(cin, name);
							cout << "Enter price per gram: ";
							cin >> pricePergram;
							cout << "Enter total weight: ";
							cin >> totalWeight;


							try
							{
								restaurant.AddIngridientToStock(name, pricePergram, totalWeight);
								restaurant.WriteToFileIngridients(restaurant.stock);
								cout << "Added" << endl;
							}
							catch (string ex)
							{
								cout << "Error: " << ex << endl;
							}
						}
						else if (choice2 == 11) {
							cin.ignore();
							system("cls");
							cout << "Increase budget" << endl;
							string cardNumber, cvv;
							int month, year;
							float income;
							cout << "Enter card number(16 digit): ";
							getline(cin, cardNumber);
							cout << "Enter month: ";
							cin >> month;
							cout << "Enter year: ";
							cin >> year;
							cin.ignore();
							cout << "Enter cvv: ";
							getline(cin, cvv);
							cout << "Enter income: ";
							cin >> income;
							try
							{
								restaurant.IncreaseWallet(cardNumber, month, year, cvv, income);
								cout << "Income: " << income << endl;
							}
							catch (string ex)
							{
								cout << "Error: " << ex << endl;


							}

						}
						else if (choice2 == 12) {
							system("cls");
							string name;
							int choice4;
							cin.ignore();
							cout << "Enter meal to change: ";
							getline(cin, name);
							int index = restaurant.SearchFood(name);
							cout << "|1.Update meal's name" << endl;
							cout << "|2.Update meal's ingredients" << endl;
							cout << "|3.Update meal's price" << endl;
							cout << "|4.Update meal's description" << endl;
							cout << "Choose: ";
							cin >> choice4;
							if (choice4 == 1) {
								cin.ignore();
								string new_name;
								cout << "Enter new name: ";
								getline(cin, new_name);
								restaurant.menu[index].SetName(new_name);
								restaurant.WriteToFileFood(restaurant.menu);
							}
							else if (choice4 == 2) {
								string Iname;
								float Iweight;
								int count;
								int index;
								int indexFood;
								float price = 0;
								DoubleLinkedList<Ingridient>ingridientsFood;
								cout << "How many new ingridients will be the meal consist of - ";
								cin >> count;
								cin.ignore();
								for (size_t i = 0; i < count; i++)
								{
									cout << "Enter " << i + 1 << " th ingridinent: ";
									getline(cin, Iname);
									cout << "Enter that ingridient's weight: ";
									cin >> Iweight;
									cin.ignore();
									index = restaurant.SearchInStock(Iname);
									if (index != -1) {
										if (restaurant.IsEnough(Iname, Iweight)) {
											Ingridient& ingridient = restaurant.GetFromStock(index);
											price += ingridient.GetPricePerGram() * Iweight;
											ingridientsFood.AddEnd(ingridient);
										}
									}
									indexFood = restaurant.SearchFood(name);
									restaurant.menu[indexFood].SetIngridients(ingridientsFood);
									restaurant.menu[indexFood].SetPrice(price);
									cout << "Changed" << endl;
									restaurant.WriteToFileFood(restaurant.menu);
								}
							}
							else if (choice4 == 3) {
								float new_price;
								cout << "Enter new price: ";
								cin >> new_price;
								restaurant.menu[index].SetPrice(new_price);
								restaurant.WriteToFileFood(restaurant.menu);
							}
							else if (choice4 == 4) {
								cin.ignore();
								string new_descp;
								cout << "Enter new description: ";
								getline(cin, new_descp);
								restaurant.menu[index].SetDescription(new_descp);
								restaurant.WriteToFileFood(restaurant.menu);
							}
						}
						else if (choice2 == 13) {
							system("cls");
							
							user.ReadFromFileHistory(user.history);

						}
						else if (choice2 == 14) {
							system("cls");
							cout << "Restaurant's budget: " << restaurant.GetRestaurantsWallet() << endl;
						}
						else if (choice2 == 15) {
							system("cls");
							main();
						}
					}
				}
				else {
					cout << "Password is wrong..." << endl;
				}
			}
			else {
				cout << "Username is wrong..." << endl;
			}
		}

	}
	else if (choice == 2) {

		int choice2;
		bool flag2 = true;
		while (flag2) {
			cout << "1.Sign up" << endl;
			cout << "2.Sign in" << endl;
			cout << "3.Exit" << endl;
			cout << "4.Back to register" << endl;
			cout << "Choose: ";
			cin >> choice2;
			if (choice2 == 1) {
				bool flag;
				string username, password, phone_numebr, mail;
				int age;
				for (size_t i = 0; i < 3; i++)
				{
					system("cls");
					cin.ignore();
					cout << "Enter username: ";
					getline(cin, username);
					cout << "Enter password: ";
					getline(cin, password);
					cout << "Enter phone number: ";
					getline(cin, phone_numebr);
					cout << "Enter mail: ";
					getline(cin, mail);
					cout << "Enter age: ";
					cin >> age;
					cout << "_______________________" << endl;
					try
					{
						User user(username, password, phone_numebr, mail, age);
						admin.users.AddEnd(user);
						admin.WriteToFile(admin.users);
						system("cls");
						cout << "Added..." << endl;
					}
					catch (string ex)
					{
						system("cls");
						cout << "Error: " << ex << endl;
						i--;
					}
					break;

					if (i == 2) {
						cout << "You have reached the limit.Try later." << endl;
					}
				}

			}
			else if (choice2 == 2) {
				string username, password;
				bool flag;
				cin.ignore();
				for (size_t i = 0; i < 3; i++)
				{
					cout << "Enter username: ";
					getline(cin, username);
					cout << "Enter password: ";
					getline(cin, password);
					try
					{
						flag = admin.SignIn(username, password);
						User& user1 = admin.SearchUserReturnUser(username);
						if (flag == true) {
							system("cls");
							cout << "Welcome" << endl;

							i = 2;
							flag2 = false;
							int  choice3;
							while (true) {
								cout << "|1.Look menu: " << endl;
								cout << "|2.Search meal: " << endl;
								cout << "|3.History: " << endl;
								cout << "|4.Card: " << endl;

								cout << "|5.Back to register: " << endl;
								cout << "|6.Exit: " << endl;
								cout << "|Choose: ";
								cin >> choice3;
								if (choice3 == 1) {
									cout << "Menu: " << endl;
									restaurant.ShowAllForUser();
								}
								else if (choice3 == 2) {
									system("cls");
									int choice5;
									string name;

									Food food;

									cin.ignore();
									cout << "Enter name: ";
									getline(cin, name);
									try
									{
										restaurant.ShowOneFood(name);
										food = restaurant.ReturnOneFood(name);
									}
									catch (string ex)
									{
										main();
									}

									cout << "1.Add to card" << endl;
									cout << "2.Back" << endl;
									cout << "Choose: ";
									cin >> choice5;
									if (choice5 == 1) {

										user1.AddToCard(food);

										cout << "Added..." << endl;
										Sleep(350);
										system("cls");
									}
									else if (choice5 == 2) {
										cout << "Menu: " << endl;
										restaurant.ShowAllForUser();
									}



								}
								else if (choice3 == 3) {
									system("cls");
									user1.ReadFromFileHistoryOneUser(user1.GetUsername(), user1.history);
									user1.ShowHistory();
								}

								else if (choice3 == 4) {
									system("cls");
									user1.ShowCard();
									int choice6;
									cout << "1.Confirm the order" << endl;
									cout << "2.Keep looking" << endl;
									cout << "Choose: ";
									cin >> choice6;
									cin.ignore();
									if (choice6 == 1) {
										string cardNumber, cvv;
										int month, year;

										for (size_t i = 0; i < 2; i++)
										{
											cout << "Enter card number(16 digit): ";
											getline(cin, cardNumber);
											cout << "Enter month: ";
											cin >> month;
											cout << "Enter year: ";
											cin >> year;
											cout << "Enter cvv: ";
											cin.ignore();
											getline(cin, cvv);
											try
											{
												cout << "Successfully bought..." << endl;
												restaurant.IncreaseWallet(cardNumber, month, year, cvv, user1.GetTotalPriceCard());
												user1.AddToHistoryList(user1.card);
												i = 3;
												restaurant.ShowAllFoods();
												for (size_t i = 0; i < user1.card.Size(); )
												{
													if (user1.card.Size() != 0) {
														user1.card.DeleteEnd();
													}
												}
												user1.WriteToFileHistory(user1.GetUsername(), user1.history);
											}
											catch (string ex)
											{
												cout << "Paymet could not be successful...";
												i--;
											}
										}
									}
									else if (choice6 == 2) {
										restaurant.ShowAllFoods();
									}
								}

								else if (choice3 == 5) {
									system("cls");
									main();
								}
								else if (choice3 == 6) {
									break;
								}
								else {
									break;
								}

							}

						}
					}
					catch (string ex)
					{
						system("cls");
						cout << "Error: " << ex << endl;
						i--;
					}

				}

			}
			else if (choice2 == 3) {
				break;
			}
			else if (choice2 == 4) {
				system("cls");
				main();
			}

			else {
				cout << "Wrong input..." << endl;
				main();
			}
		}

	}
	else {
		system("cls");
		main();
	}


}
