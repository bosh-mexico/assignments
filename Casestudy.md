# 🚗 Vehicle Speed Governor (VSG) – Product Requirements

## 1. Purpose
The Vehicle Speed Governor ensures that vehicles do not exceed a pre-set maximum speed, thereby:
- Enhancing road safety.
- Ensuring compliance with regulatory speed limits.
- Improving fuel efficiency and reducing emissions.

---

## 2. Stakeholders
- **Regulatory Authorities** – Ensure compliance with government mandates.  
- **Fleet Operators / Logistics Companies** – Maintain safety and reduce liability.  
- **OEMs (Vehicle Manufacturers)** – Integrate VSG into production vehicles.  
- **Drivers** – Directly interact with the governed system.  

---

## 3. Functional Requirements
1. **Speed Limiting**
   - Must cap vehicle speed at a configurable threshold (e.g., 80 km/h for trucks, 100 km/h for buses).
   - Threshold should be programmable via secure interface (OBD-II, CAN, or external tool).

2. **Vehicle Interface**
   - Integrate with **ECU / engine control** (via CAN bus or throttle actuator).
   - Override acceleration commands when vehicle reaches governed speed.
   - Ensure smooth control (no sudden jerks or unsafe deceleration).

3. **Alerts & Indications**
   - Provide driver feedback when governed speed is reached (dashboard indicator, audible beep, or both).
   - Log events when governor activates (for fleet management / compliance audits).

4. **Tamper Resistance**
   - Prevent unauthorized changes to speed settings.
   - Seal hardware with tamper-evident mechanisms.
   - Support encryption/authentication for configuration updates.

5. **Fail-Safe Behavior**
   - In case of system fault, default to safe mode without disabling vehicle operation.
   - Ensure governor does not interfere with braking, steering, or emergency maneuvers.

6. **Diagnostics & Logging**
   - Store fault codes, activation logs, and tamper attempts.
   - Support reading logs via standard diagnostic tools.

7. **Power & Connectivity**
   - Powered from vehicle’s battery (12V / 24V).
   - Must handle transient voltage spikes and surges.

---

## 4. Non-Functional Requirements
1. **Performance**
   - Response time: must adjust throttle within 200ms of crossing speed threshold.
   - Accuracy: ±2 km/h speed control.

2. **Reliability**
   - MTBF (Mean Time Between Failures) ≥ 50,000 hours.
   - Operating temperature: -40°C to +85°C (automotive grade).

3. **Compliance**
   - Must meet ISO 26262 (Functional Safety).
   - Must meet relevant country-specific VSG regulations (e.g., AIS-018 in India, UNECE R89 in Europe).

4. **Security**
   - Configurations must be password-protected or cryptographically secured.
   - Logs should be tamper-proof.

---

## 5. Constraints
- Must be compatible with both manual and automatic transmission vehicles.
- Must not affect emergency acceleration when overtaking (temporary override may be allowed per regulation).
- Installation should not exceed 2 hours.

---

## 6. Testing & Validation
1. **Unit Testing** – Verify each module (speed sensing, throttle control, alerts).
2. **Integration Testing** – ECU + CAN bus communication validation.
3. **Vehicle Road Testing** – Confirm governed speed, safety, and smoothness.
4. **Tamper Testing** – Ensure system resists bypass attempts.
5. **Environmental Testing** – Vibration, dust, humidity, EMI/EMC compliance.

---

## 7. Future Enhancements
- GPS-based variable speed limits (e.g., 30 km/h in city zones, 80 km/h on highways).
- Cloud integration for fleet monitoring.
- AI-based driver behavior analytics.
- 

```
using System;

namespace VehicleSpeedGovernor
{
    // 🚨 God Class: Handles everything in one place
    public class VehicleSpeedGovernor
    {
        // Configurable threshold
        private int speedThreshold;

        // Vehicle State
        private int currentSpeed;
        private bool isGovernorActive;

        // Constructor
        public VehicleSpeedGovernor(int initialThreshold)
        {
            speedThreshold = initialThreshold;
            currentSpeed = 0;
            isGovernorActive = false;
        }

        // Configure threshold (via secure tool / interface)
        public void SetSpeedThreshold(int threshold)
        {
            if (threshold <= 0)
            {
                Console.WriteLine("Invalid threshold!");
                return;
            }
            speedThreshold = threshold;
            Console.WriteLine($"[CONFIG] Threshold set to {speedThreshold} km/h");
        }

        // Simulate reading vehicle speed (from ECU/OBD-II)
        public void UpdateVehicleSpeed(int newSpeed)
        {
            currentSpeed = newSpeed;
            Console.WriteLine($"[DATA] Vehicle speed updated: {currentSpeed} km/h");
            CheckAndEnforceSpeedLimit();
        }

        // Core logic: Enforce speed limit
        private void CheckAndEnforceSpeedLimit()
        {
            if (currentSpeed > speedThreshold)
            {
                isGovernorActive = true;
                OverrideAcceleration();
                ProvideDriverFeedback();
                LogEvent();
            }
            else
            {
                isGovernorActive = false;
            }
        }

        // Interface with ECU/throttle
        private void OverrideAcceleration()
        {
            Console.WriteLine("[ECU] Acceleration overridden to maintain threshold.");
        }

        // Driver feedback
        private void ProvideDriverFeedback()
        {
            Console.WriteLine("[ALERT] Speed limit reached!");
            Console.Beep();
        }

        // Logging events
        private void LogEvent()
        {
            Console.WriteLine($"[LOG] Governor activated at speed {currentSpeed} km/h (Threshold: {speedThreshold})");
        }

        // Utility: Show system status
        public void ShowStatus()
        {
            Console.WriteLine($"[STATUS] Current Speed: {currentSpeed}, Threshold: {speedThreshold}, Governor Active: {isGovernorActive}");
        }
    }
}

```
