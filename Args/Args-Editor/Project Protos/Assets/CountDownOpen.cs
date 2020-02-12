﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CountDownOpen : MonoBehaviour
{
    [Range(0.0f,180.0f)] [SerializeField] private float AmountTime;
    private float Time;
    [SerializeField] private Door DoorToOpen;

    private bool Activated;
    private float TimePassed;

    void Start()
    {
        
    }

    void Update()
    {
        Time = AmountTime * 60;
        if (Activated)
        {
            if (TimePassed >= Time)
            {
                Activated = false;
                DoorToOpen.open = false;
                TimePassed = 0;
            }
            TimePassed++;
            DoorToOpen.open = true;
        }
    }

    void OnTriggerStay(Collider other)
    {
        if (Input.GetKeyDown(KeyCode.Space) || Input.GetKeyDown(KeyCode.RightShift) || Input.GetButtonDown("PS4_SQUARE"))
        {
            Activated = true;
        }
    }


}
