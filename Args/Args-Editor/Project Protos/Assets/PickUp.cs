using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUp : MonoBehaviour
{
    public bool pickup = false;
    public bool inFront = false;
    private GameObject pickuped;
    [SerializeField] private float VertThrowStrength;
    [SerializeField] private float HorThrowStrength;

    void Update()
    {
        if (pickup)
        {
            if (Input.GetKeyUp(KeyCode.Space))
            {
                pickuped.transform.parent = transform.parent;
                pickup = false;
                pickuped.GetComponent<Rigidbody>().AddForce(transform.forward* HorThrowStrength);
                pickuped.GetComponent<Rigidbody>().AddForce(transform.up* VertThrowStrength);
                pickuped = null;
            }
        }
    }

    void OnTriggerStay(Collider other)
    {
        if (other.transform.CompareTag("PickUp"))
        {
            inFront = true;
            if (Input.GetKeyDown(KeyCode.Space))
            {
                if (!pickup)
                {
                    pickup = true;
                    other.transform.parent = transform;
                    pickuped = other.gameObject;
                }
            }
        }
    }

    void OnTriggerExit(Collider other)
    {
        if (other.transform.CompareTag("PickUp"))
        {
            inFront = false;
        }
    }
}
