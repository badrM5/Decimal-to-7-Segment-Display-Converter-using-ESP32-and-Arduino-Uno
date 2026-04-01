int nombre = 0;

void setup() {
  Serial.begin(19200);
  Serial.println("Entrez un nombre decimal : ");
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(23,OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    nombre = Serial.parseInt();  // Lit un entier décimal
    Serial.readString();         // Vide le buffer
    
    Serial.print("Nombre decimal : ");
    Serial.println(nombre);
    
    Serial.print("Binaire : ");
    Serial.println(nombre, BIN);  // Affiche en binaire
    
    // Extraire bits BCD A, B, C, D
    int D = (nombre >> 0) & 1;
    int C = (nombre >> 1) & 1;
    int B = (nombre >> 2) & 1;
    int A = (nombre >> 3) & 1;
    bool a= (A) || (C) || (B&&D)|| (!D&&!B) ;
    bool b = !B || (!C && !D) || (C && D);
    bool c = !C || B || D;
    bool d = A || (!B && !D) || (C && !D) || (!B && C) || (B && !C && D);
    bool e = (C && !D) || (!B && !D);
    bool f = (!C && !D) || A || (B && !C) || (B && !D);
    bool g = A || (C && !D) || (B && !C) || (!B && C);
    digitalWrite(2, a ? HIGH : LOW);
    digitalWrite(4, b ? HIGH : LOW);
    digitalWrite(22, c ? HIGH : LOW);
    digitalWrite(18, d ? HIGH : LOW);
    digitalWrite(19, e ? HIGH : LOW);
    digitalWrite(21, f ? HIGH : LOW);
    digitalWrite(23, g ? HIGH : LOW);
    
    
    
  }
}