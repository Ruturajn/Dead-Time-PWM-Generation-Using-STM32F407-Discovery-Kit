# Dead-Time-PWM-Generation-Using-STM32F407-Discovery-Kit

![IMG20211212141617](https://user-images.githubusercontent.com/56625259/145706272-1cc3dc34-f436-48e9-b715-449ffebaa73b.jpg)

The PWM waveforms are genrated using Timer 1 (Advanced Timer) on the STM32F407 Discovery Kit. TIM1_CH1 and TIM1_CH1N are the channels that generate the complementary output signals along with Dead Time Insertion which are known as OC1 and OC1N respectively. The frequency of the signal generated is configured to be 20KHz. The Connections from the STM32F407 Discovery Board to the Logic Analyser are:

| STM32F407 | Logic Analyser |
| ---- | ---- |
| PA8 | Channel 0 |
| PB13 | Channel 1 |

The screenshots of the Logic analyser below show the captured waveforms with a Dead Time of 5 microseconds.

![Screenshot 2021-12-12 141907](https://user-images.githubusercontent.com/56625259/145706211-099f6007-3a00-441a-b70a-fde1380b8f04.png)

![Screenshot 2021-12-12 141925](https://user-images.githubusercontent.com/56625259/145706227-c27b31ff-e1fd-4bda-bd5a-7dafbc22998e.png)

![Screenshot 2021-12-12 141419](https://user-images.githubusercontent.com/56625259/145706313-cae9652e-b264-4464-aa40-29f79af13bf4.png)

![Screenshot 2021-12-12 142456](https://user-images.githubusercontent.com/56625259/145706314-47866fb4-08da-488b-98e0-c2124b68d6be.png)
