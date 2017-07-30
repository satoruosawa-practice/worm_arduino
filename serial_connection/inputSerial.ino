void inputSerial(int &received_value) {
  char c = Serial.read();
  if ('0' <= c && c <= '9') {
    received_value = int(c - '0');
  }
  //  /* 'a' から 'f' の文字なら(capital→small) */
  //  else if ('a' <= (c = tolower(str)) && c <= 'f') {
  //    incomingTar=int(c - 'a' + 10);
  //  }
  //
  //  /*fadeの時間*/
  //  else if ('g' == (c = tolower(str))){fadetime = 0;}
  //  else if ('h' == (c = tolower(str))){fadetime = 2.0;}
  //  else if ('i' == (c = tolower(str))){fadetime = 2.5;}
  //  else if ('j' == (c = tolower(str))){fadetime = 3;}
  //  else if ('k' == (c = tolower(str))){fadetime = 3.5;}
  //  else if ('l' == (c = tolower(str))){fadetime = 4;}
  //  else if ('m' == (c = tolower(str))){fadetime = 4.5;}
  //  else if ('n' == (c = tolower(str))){fadetime = 5;}
  //  else if ('o' == (c = tolower(str))){fadetime = 5.5;}
  //  else if ('p' == (c = tolower(str))){fadetime = 22.5;}
  //
  //  /*fadeカーブの0点x値*/
  //  else if ('q' == (c = tolower(str))){powered = 1;}
  //  else if ('r' == (c = tolower(str))){powered = 2;}
  //  else if ('s' == (c = tolower(str))){powered = 3;}
  //  else if ('t' == (c = tolower(str))){powered = 4;}
  //  else if ('u' == (c = tolower(str))){powered = 5;}
  //
  //  /*待ち時間*/
  //  else if ('x' == (c = tolower(str))){delaytime = delaytime+1;} //+1秒
  //  else if ('y' == (c = tolower(str))){if(delaytime >= 1){delaytime = delaytime - 1;}}    //-1秒
  //  else if ('z' == (c = tolower(str))){delaytime = 0;}   //0秒
  //
  //  /*その他の値は無視*/
}

