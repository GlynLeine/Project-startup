using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pressure : MonoBehaviour
{
    [SerializeField] private Door DoorToOpen;

    void OnTriggerStay(Collider other)
    {
        DoorToOpen.open = true;
    }

    void OnTriggerExit(Collider other)
    {
        DoorToOpen.open = false;
    }
}
