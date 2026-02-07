int RECV_PIN=2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void initIRREMOTE(){ irrecv.enableIRIn(); }

void decodeIRR(){
  long val=0;
  if(irrecv.decode(&results)){
    val=results.value;
    //display.setCursor(16,16);
    /*display.print(String(val, HEX));
    display.println(String(" HEX"));
    display.print(String(val, DEC));
    display.println(String(" DEC"));*/
    irrecv.resume();
    switch (val){
      case -1: break;
      case 255: break;
      case 16753245: display.println(String("CH-")); break;
      case -484956645: display.println(String("CH-")); break;
      case 16736925: display.println(String("CH")); break;
      case 5316027: display.println(String("CH")); break;
      case 16769565: display.println(String("CH+")); break;
      case -293048961: display.println(String("CH+")); break;
      case 16720605: display.println(String("PREV")); break;
      case 1386468383: display.println(String("PREV")); break;
      case 16712445: display.println(String("NEXT")); break;
      case -672642277: display.println(String("NEXT")); break;
      case 16761405: display.println(String("PLAY/PAUSE")); break;
      case 553536955: display.println(String("PLAY/PAUSE")); break;
      case 16769055: display.println(String("VOL-")); break;
      case -260652741: display.println(String("VOL-")); break;
      case 16754775: display.println(String("VOL+")); break;
      case -1547112997: display.println(String("VOL+")); break;
      case 16748655: display.println(String("EQ")); break;
      case -439370369: display.println(String("EQ")); break;
      case 16738455: display.println(String("0")); break;
      case -1056840325: display.println(String("0")); break;
      case 16750695: display.println(String("100+")); break;
      case -1756873733: display.println(String("100+")); break;
      case 16756815: display.println(String("200+")); break;
      case -255584701: display.println(String("200+")); break;
      case 16724175: display.println(String("1")); break;
      case -1760117185: display.println(String("1")); break;
      case 16718055: display.println(String("2")); break;
      case 1033561079: display.println(String("2")); break;
      case 16743045: display.println(String("3")); break;
      case 1635910171: display.println(String("3")); break;
      case 16716015: display.println(String("4")); break;
      case -1943902853: display.println(String("4")); break;
      case 16726215: display.println(String("5")); break;
      case 1217346747: display.println(String("5")); break;
      case 16734885: display.println(String("6")); break;
      case 71952287: display.println(String("6")); break;
      case 16728765: display.println(String("7")); break;
      case 851901943: display.println(String("7")); break;
      case 16730805: display.println(String("8")); break;
      case 465573243: display.println(String("8")); break;
      case 16732845: display.println(String("9")); break;
      case 1053031451: display.println(String("9")); break;
      default: display.println(String(val, DEC)); break;
    }
    delay(300);
  }
}