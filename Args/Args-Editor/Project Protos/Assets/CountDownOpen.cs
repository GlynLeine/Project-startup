    using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CountDownOpen : MonoBehaviour
{
    [Range(0.0f,180.0f)] [SerializeField] private float AmountTime;
    private float Time;
    [SerializeField] private List<Door> DoorsToOpen;
    [SerializeField] private List<Door> DoorsToClose;
    [SerializeField] private bool Timed;

    public bool Activated;
    private float TimePassed;

    void Start()
    {
        Time = AmountTime * 60;
    }

    void Update()
    {

        if (Activated)
        {
            
            if (Timed)
            {
                if (TimePassed >= Time)
                {
                    Activated = false;
                    foreach (Door door in DoorsToOpen)
                    {
                        door.open = false;
                    }
                    foreach (Door door in DoorsToClose)
                    {
                        door.open = true;
                    }
                    TimePassed = 0;
                }
                TimePassed++;
            }
        }
    }

    void OnTriggerStay(Collider other)
    {
        if (Input.GetKeyDown(KeyCode.Space) || Input.GetKeyDown(KeyCode.RightShift) || Input.GetButtonDown("PS4_SQUARE") || Input.GetButtonDown("PS4_SQUARE_2"))
        {
            if (!Activated)
            {
                foreach (Door door in DoorsToOpen)
                {
                    door.open = true;
                }
                foreach (Door door in DoorsToClose)
                {
                    door.open = false;
                }
                Activated = true;
            }
            else
            {
                foreach (Door door in DoorsToOpen)
                {
                    door.open = false;
                }
                foreach (Door door in DoorsToClose)
                {
                    door.open = true;
                }
                Activated = false;

            }
        }
    }


}
