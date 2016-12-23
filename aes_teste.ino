#include <aes256.h> //Include library files


void setup() {
  Serial.begin(115200);
  String keyStr = "12345678901234561234567890123456";
  uint8_t key[keyStr.length()];
  for(int c = 0; c < sizeof(key); c++){
    key[c] = keyStr.charAt(c);
  }

  Serial.print("KEY: ");
  printHex(key, sizeof(key));

  aes256_context ctxt;
  aes256_init(&ctxt, key);

  String texto = "asdfasdfasdf tes";
  uint8_t data[texto.length()];
  for(int c = 0; c < sizeof(data); c++){
    data[c] = texto.charAt(c);
  }

  Serial.print("ORIGINAL: ");
  printHex(data, sizeof(data));

  aes256_encrypt_ecb(&ctxt, data);

  Serial.print("ENCRYPTED: ");
  printHex(data, sizeof(data));
}

void printHex(int8_t  *value, int size){
  int i;
  Serial.println(size);
  for(i = 0; i < size; i++){
    if ((byte)value[i] < 16) {
       Serial.print("0");
    }
    Serial.print((byte)(value[i]), HEX);
  }
  Serial.println();
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
