# STM32F103 36-Tap FIR Filter & Proteus Simulation

This project implements a **36-tap discrete-time FIR (Low-Pass) filter** on an **STM32F103C8T6** microcontroller, operating at a **1 kHz sampling rate** (1 ms period) with an 8-bit **DAC0808** parallel output. The system hardware and digital signal processing (DSP) pipeline are simulated and verified in Proteus (ISIS).

## 🛠️ System Architecture & Specifications
* **Microcontroller:** STM32F103C8T6 (Bare-metal C/C++)
* **Input (ADC):** Analog signal acquisition via the `PA0` pin (12-bit ADC data scaled down to 8-bit).
* **Output (DAC):** Parallel 8-bit data bus on `PB0–PB7` driving a DAC0808 and an Op-Amp Transimpedance Amplifier (TIA) for analog output.
* **Filter Design:** 36-coefficient FIR Low-Pass Filter.
* **Operation Modes:**
  * **Mode 1 (Test):** Internal sine wave generation and verification.
  * **Mode 2 (Passthrough):** Direct data transfer from ADC to DAC without filtering (used to observe the Zero-Order Hold effect).
  * **Mode 3 (Filter Active):** 36-tap FIR filter algorithm is enabled.

## ⚡ Proteus Simulation & Engineering Note
The default `STM32F1XX.DLL` engine in the Proteus simulation environment experiences "excessive CPU load" and synchronization lockups during hardware Timer (TRGO) triggered ADC-DMA loops. To ensure real-time data flow without compromising the hardware realism of the simulation:
* The DMA architecture was bypassed, and ADC readings were shifted to a Software Interrupt / Polling logic, effectively overcoming the simulator's hardware communication bottleneck.
* To stabilize ADC readings, the MCU's hidden analog reference pins (VDDA / VSSA) were explicitly routed to physical power rails, and necessary capacitive/resistive loads (1nF bypass) were added for the SPICE engine.
<img width="1181" height="822" alt="image" src="https://github.com/user-attachments/assets/ea99a11a-a23a-4bd0-b088-5c417332cc53" />
<img width="1372" height="876" alt="image" src="https://github.com/user-attachments/assets/7a232bee-dcb7-4770-982a-c015082d7c20" />
<img width="676" height="460" alt="image" src="https://github.com/user-attachments/assets/fcdac74e-1b6c-450a-96c3-6c0ca40285b6" />


