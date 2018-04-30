#define WAITLOW(pin) while (digitalRead(pin) != 0);
#define WAITHIGH(pin) while (digitalRead(pin) != 1);

int clockPin = 3;
int dataPin = 2;
int buzzerPin = 12;
int ledPin = 13;
String budget;
String food[] = {"Apples", "Oranges", "Grape Soda", "Milk", "Eggs"};
double price[] = {1.99, 2.99, 5.99, 2.59, 1.59};
int numofFood[5] = {0};
double static total = 0;
double static finalBudget = 0;
double tax = 0.06;
double static totalTax = 0;
static volatile uint8_t head;
#define BUFFER_SIZE 45
static volatile uint8_t buffer[BUFFER_SIZE];
unsigned long lastScan = 0;
boolean scanCorrect = true;
boolean keepRunning = true;
int scannedInt = 0;
byte keymap[] = {0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, '`', 0,
        0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'q', '1', 0,
        0, 0, 'z', 's', 'a', 'w', '2', 0,
        0, 'c', 'x', 'd', 'e', '4', '3', 0,
        0, ' ', 'v', 'f', 't', 'r', '5', 0,
        0, 'n', 'b', 'h', 'g', 'y', '6', 0,
        0, 0, 'm', 'j', 'u', '7', '8', 0,
        0, ',', 'k', 'i', 'o', '0', '9', 0,
        0, '.', '/', 'l', ';', 'p', '-', 0,
        0, 0, '\'', 0, '[', '=', 0, 0,
        0 /*CapsLock*/, 0 /*Rshift*/, 0 /*Enter*/, ']', 0, '\\', 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, '1', 0, '4', '7', 0, 0, 0,
        '0', '.', '2', '5', '6', '8', 0, 0 /*NumLock*/,
        0, '+', '3', '-', '*', '9', 0, 0,
        0, 0, 0, 0 };

void setup() {
  pinMode(clockPin, INPUT_PULLUP);
  pinMode(dataPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("SMART KART");
  delay(200);
  while (! Serial);
  Serial.println("Enter the budgeted amount you plan to spend. (Press [ENTER] and Begin Scanning)\n");
}

void loop() {
  while(keepRunning){
    getBudget();
    WAITLOW(clockPin);
    WAITHIGH(clockPin);
    unsigned char keycode = 0;
    for (uint8_t i = 0; i < 8; i++) {
      WAITLOW(clockPin);
      keycode >>= 1;
      if (digitalRead(dataPin)) {
        keycode |= 0x80;
      }
      WAITHIGH(clockPin);
    }
    buffer[head++] = keycode;
    WAITLOW(clockPin);
    WAITHIGH(clockPin);
    WAITLOW(clockPin);
    WAITHIGH(clockPin);
    unsigned long time = millis();
    scanCorrect = true;
    if (head == 5 && lastScan - time > 2000) {
      scannedInt = keymap[buffer[3]] - '0';
      if (scannedInt > 0) {
        scannedItem(scannedInt);
        digitalWrite(ledPin, HIGH);                                          
        delay(300);                                                          
        digitalWrite(ledPin, LOW); 
      } else {
        scanCorrect = false;
      }
      head = 0;
      lastScan = time;
      for (int i = 0; i < 5; i++) buffer[i] = 0;
    }
  }
}

void scannedItem(int si){
  for(int i = 0; i < 5; i++){
    if((i+1) == si){
      Serial.println("***** Detected Scan *******");
      //Serial.println(scannedInt);
      Serial.println(food[i]);
      Serial.print("Price: $");
      Serial.println(price[i]);
      numofFood[i]++;
      total += price[i];
      totalTax = total + (total * tax); 
      Serial.print("Amount Due: $");
      Serial.println(totalTax);
      Serial.println("__________________");
    } 
  }
  if(totalTax  >= finalBudget){
    overBudget();
  }
  else{
    Serial.print("Money Left: $");
    Serial.println(finalBudget - totalTax);
    Serial.println();
    if(finalBudget - totalTax <= 5){
      checkBudget();
    }
  }
}

void getBudget(){
  while (Serial.available() > 0){
    char rc = Serial.read();
    budget += rc;
  }
    finalBudget = budget.toDouble();
  while (Serial.available() > 0){
    Serial.read();
  }
}

void overBudget(){
  char answer;
  double overbudget = finalBudget - totalTax;
  Serial.print("OVERBUDGET: $");
  Serial.println(overbudget);
  Serial.println();
  tone(buzzerPin, 100);
  delay(1000);
  noTone(buzzerPin);
  Serial.println("Would you like to take an item out? (ENTER Y or N)");
  answer = inquiry();
  if(answer == 'y'){
    Serial.println("What item would you like to take out? (Enter the Corresponding Number)\n");
    subtractItem();
    Serial.print("\nAdjusted Amount Due: $");
    totalTax = total + (total * tax);
    Serial.println(totalTax);
    if(finalBudget - totalTax <= 5){
      checkBudget();
    }
    else{
      Serial.println("Resume Shopping.\n");
    }
  }
  else if(answer == 'n'){
    Serial.println("Do you want to continue shopping or stop? (ENTER Y or N)\n");
    answer = inquiry();
    if(answer == 'y'){
      Serial.println("Resume Shopping \n");
    }
    else if(answer = 'n'){
      endShopping(); 
    }
  }
}

char inquiry(){
  char answer;
  char temp;
  while(true){
    if (Serial.available() > 0){
      temp = Serial.read();
      if(temp == 'y' || temp == 'Y') {
        answer = 'y';
        break;
      }
      else if(temp == 'n' || temp == 'N'){
        answer = 'n';
        break;
      }
    }
  }
  while (Serial.available() > 0) {
    Serial.read();
  }
  return answer;
}

void subtractItem(){
  int hm;
  int rem = 0;
  char temp;
  int count = 0;
  shoppingList();
  while(true){
    if (Serial.available() > 0){
      temp = Serial.read();
      if(temp == '1'){
        if(numofFood[0] == 0){
          Serial.println("There are no Apples in the cart.");
          Serial.println("\nWhat item would you like to take out? (Enter the Corresponding Number)\n");
          subtractItem();
        }
        else if(numofFood[0] > 1){
          hm = howMany(0); 
          total -= (price[0] * hm);
          numofFood[0] -= hm;
          Serial.print(hm);
          Serial.println(" Apples taken out the shopping cart.");
        }
        else{
          total -= (price[0] * numofFood[0]);
          Serial.println("Apples taken out the shopping cart.");
          numofFood[0] = 0;
        }
        break;
      }
      else if(temp == '2'){
        if(numofFood[1] == 0){
          Serial.println("There are no Oranges in the cart.");
          Serial.println("\nWhat item would you like to take out? (Enter the Corresponding Number)\n");
          subtractItem();
        }
        else if(numofFood[1] > 1){
          hm = howMany(1);
          total -= (price[1] * hm);
          numofFood[1] -= hm;
          Serial.print(hm);
          Serial.println(" Oranges taken out the shopping cart.");
        }
        else{   
          total -= (price[1] * numofFood[1]);
          Serial.println("Oranges taken out the shopping cart.");
          numofFood[1] = 0;
        }
        break;
      }
      else if(temp == '3'){  
        if(numofFood[2] == 0){
          Serial.println("There are no Grape Sodas in the cart");
          Serial.println("\nWhat item would you like to take out? (Enter the Corresponding Number)\n");
          subtractItem();
        }
        else if(numofFood[2] > 1){
          hm = howMany(2);
          total -= (price[2] * hm);
          numofFood[2] -= hm;
          Serial.print(hm);
          Serial.println(" Grape Soda taken out the shopping cart");
        }
        else{
          total -= (price[2] * numofFood[2]);
          Serial.println("Grape Soda taken out the shopping cart.");
          numofFood[2] = 0;
        }
        break;
      }
      else if(temp == '4'){ 
        if(numofFood[3] == 0){
          Serial.println("There is no Milk in the cart.");
          Serial.println("\nWhat item would you like to take out? (Enter the Corresponding Number)\n");
          subtractItem();
        } 
        else if(numofFood[3] > 1){
          hm = howMany(3);
          total -= (price[3] * hm);
          numofFood[3] -= hm;
          Serial.print(hm);
          Serial.println(" Milks taken out the shopping cart.");
        }
        else{
          total -= (price[3] * numofFood[3]);
          Serial.println("Milk taken out the shopping cart.");
          numofFood[3] = 0;
        }
        break;
      }
      else if(temp == '5'){ 
        if(numofFood[4] == 0){
          Serial.println("There are no Eggs in the cart.");
          Serial.println("\nWhat item would you like to take out? (Enter the Corresponding Number)\n");
          subtractItem();
        }
        else if(numofFood[4] > 1){
          hm = howMany(4);
          total -= (price[4] * hm);
          numofFood[4] -= hm;
          Serial.print(hm);
          Serial.println(" Eggs taken out the shopping cart.");
        }
        else{
          total -= (price[4] * numofFood[4]);
          Serial.println("Eggs taken out the shopping cart.");
          numofFood[4] = 0;
        }
        break;
      }
    }
  }
  while (Serial.available() > 0) {
    Serial.read();
  }
}

void shoppingList(){
  for(int i = 0; i < 5; i++){
    if(numofFood[i] > 0){
      Serial.print(i + 1);
      Serial.print(".) ");
      Serial.print(food[i]);
      Serial.print("\t-----\t Number of Items:  ");
      Serial.print(numofFood[i]);
      Serial.print("\t| Price:  ");
      Serial.println(price[i]);
    }
  }
}

int howMany(int item){
  char temp;
  int num;
  int finalnum;
  Serial.print("\nHow many ");
  Serial.print(food[item]);
  Serial.println(" would you like to take out?");
  while(true){
    if(Serial.available() > 0){
      temp = Serial.read();
    }
    if(temp >= '0' && temp <= '9'){
      num = temp - '0';
      //Serial.println(num);
      if(num <= numofFood[item]){
        finalnum = num;
        break;
      }
    }
  }
  while (Serial.available() > 0) {
    Serial.read();
  }
  return finalnum;
}

void checkBudget(){
  char answer;
  Serial.println("Close to Budgeted Amount \nDo you want to continue shopping or stop? (ENTER Y or N)\n");
  answer = inquiry();
  if(answer == 'y'){
    Serial.println("\nResume Shopping \n");
  }
  else if(answer == 'n'){
    endShopping();
  }
  while (Serial.available() > 0) {
    Serial.read();
  }
}


void endShopping(){
  Serial.print("Your Total is: $");
  Serial.println(totalTax);
  Serial.println("\n----------------------------------------------------------------------");
  Serial.println("Shopping List");
  Serial.println("----------------------------------------------------------------------\n");
  shoppingList();
  Serial.println("\n\nPlease proceed to the cash register.\nTHANK YOU FOR SHOPPING!!!");
  keepRunning = false;
}

