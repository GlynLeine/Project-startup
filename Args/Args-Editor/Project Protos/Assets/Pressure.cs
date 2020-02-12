using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pressure : MonoBehaviour
{
    [SerializeField] private Door DoorToOpen;

    void OnTriggerStay(Collider other)
    {
        if(other.CompareTag("Push"))
            DoorToOpen.open = true;
        else if (other.CompareTag("PickUp"))
        {
            if (other.GetComponent<PickUp>())
            {
                if (other.GetComponent<PickUp>().pickup)
                {
                    DoorToOpen.open = true;
                }
            }
        }
        else
        {
            DoorToOpen.open = false;
        }
    }

    void OnTriggerExit(Collider other)
    {
        DoorToOpen.open = false;
    }
}
