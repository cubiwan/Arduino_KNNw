/*
  SimpleKNN

  This example demonstrates how to use the Arduino_KNN library.

  It creates a KNN classifier that expects an input array of 2 floats.
  Then adds 4 example inputs with their respective classifications.
  After this it demonstrates how to classify an input value and get
  the classification's confidence.

  This example code is in the public domain.
*/

#include <Arduino_KNN.h>

// Create a new KNNClassifier, input values are array of 2 (floats),
// change if you need a bigger input size
KNNClassifier myKNN(2);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Simple KNN");
  Serial.println();

  Serial.print("Adding examples to myKNN ... ");
  Serial.println();

  // add examples to KNN
  // if x < 3 or y < 3, class 1
  float example1_1[] = { 1.0, 1.0 };  
  float example1_2[] = { 1.0, 2.0 };  
  float example1_3[] = { 1.0, 3.0 };    
  float example1_4[] = { 1.0, 4.0 };  
  float example1_5[] = { 1.0, 5.0 };  
  float example2_1[] = { 2.0, 1.0 };  
  float example2_2[] = { 2.0, 2.0 };  
  float example2_3[] = { 2.0, 3.0 };    
  float example2_4[] = { 2.0, 4.0 };  
  float example2_5[] = { 2.0, 5.0 };  
  float example3_1[] = { 3.0, 1.0 };  
  float example3_2[] = { 3.0, 2.0 }; 
  float example4_1[] = { 4.0, 1.0 };  
  float example4_2[] = { 4.0, 2.0 }; 
  //float example5_1[] = { 5.0, 1.0 };  
  float example5_2[] = { 5.0, 2.0 }; 

  // if x > 3 and y > 3, class 2  
  float example4_4[] = { 4.0, 4.0 }; 
  float example4_5[] = { 4.0, 5.0 }; 
  float example4_6[] = { 4.0, 6.0 }; 
  float example5_4[] = { 5.0, 4.0 }; 
  float example5_5[] = { 5.0, 5.0 }; 
  float example5_6[] = { 5.0, 6.0 }; 
  float example6_4[] = { 6.0, 4.0 }; 
  float example6_5[] = { 6.0, 5.0 }; 
  float example6_6[] = { 6.0, 6.0 };   

  //add examples to KNN
  myKNN.addExample(example1_1, 1);
  myKNN.addExample(example1_2, 1);
  myKNN.addExample(example1_3, 1);
  myKNN.addExample(example1_4, 1);
  myKNN.addExample(example1_5, 1);
  myKNN.addExample(example2_1, 1);
  myKNN.addExample(example2_2, 1);
  myKNN.addExample(example2_3, 1);
  myKNN.addExample(example2_4, 1);
  myKNN.addExample(example2_5, 1);
  myKNN.addExample(example3_1, 1);
  myKNN.addExample(example3_2, 1);  
  myKNN.addExample(example4_1, 1);
  myKNN.addExample(example4_2, 1);  
  //myKNN.addExample(example5_1, 1);
  myKNN.addExample(example5_2, 1);
  
  myKNN.addExample(example4_4, 2);
  myKNN.addExample(example4_5, 2);
  myKNN.addExample(example4_6, 2);
  myKNN.addExample(example5_4, 2);
  myKNN.addExample(example5_5, 2);
  myKNN.addExample(example5_6, 2);
  myKNN.addExample(example6_4, 2);
  myKNN.addExample(example6_5, 2);
  myKNN.addExample(example6_6, 2);

  // get and print out the KNN count
  Serial.print("myKNN.getCount() = ");
  Serial.println(myKNN.getCount());
  Serial.println();

  // classify the input
  Serial.println("Classifying inputs ...");
  for(float y = 2; y < 5; y += 0.1){  
    for(float x = 2; x < 5; x += 0.1){      
      classify(x, y);
    }
  }
}

void classify(float x, float y) {
  float input[] = { x, y };   

  int classification = myKNN.classify(input, 3); // classify input with K=3
  float confidence = myKNN.confidence();

  int classificationWeighted = myKNN.classifyWeighted(input, 3); // classify input with K=3
  float confidenceWeighted = myKNN.confidence();

  // print the classification and confidence
  if(classification != classificationWeighted){
    Serial.print("!!!");
  } 
  Serial.print("{");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.print("} -> ");  
  Serial.print("classify: ");
  Serial.print(classification);
  Serial.print(" confidence: ");
  Serial.print(confidence);
  Serial.print("   #   classifyWeighted: ");
  Serial.print(classificationWeighted);
  Serial.print(" confidence: ");
  Serial.println(confidenceWeighted);
}


void loop() {
  // do nothing
}
