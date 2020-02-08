using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CustomScript : MonoBehaviour
{
    public Component[] componentList;
    // Start is called before the first frame update
    void Start()
    {
        componentList = GetComponents(typeof(Component));
    }

    public void GetComponents()
    {
        componentList = GetComponents(typeof(Component));
        for (int i = 0; i < componentList.Length; i++)
        {
            Debug.Log(componentList[i].GetType());
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
