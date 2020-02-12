using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour
{
    public bool open;
    private Vector3 StartPos;
    private Vector3 OpenPos;

    void Start()
    {
        StartPos = transform.position;
        OpenPos = StartPos + new Vector3(0, 10, 0);
        open = false;
    }

    void Update()
    {
            if (open)
            {
                transform.position = OpenPos;
            }
            else
            {
                transform.position = StartPos;
            }
        
    }
}
