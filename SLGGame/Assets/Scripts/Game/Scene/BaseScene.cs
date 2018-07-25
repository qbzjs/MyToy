﻿using Common;
using Framework.FSM;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace Game.Scene
{
    public abstract class BaseScene : FSMState
    {
        private bool m_HasLoaded = false;

        private Coroutine m_CurCoroutine;

        public BaseScene(int id) : base(id)
        {
        }

        public override void OnEnter()
        {
            base.OnEnter();
            m_HasLoaded = false;
            m_CurCoroutine = GlobalMono.Instance.StartCoroutine(Initialize());
        }

        public override void OnExit()
        {
            base.OnExit();
            if (m_CurCoroutine != null)
            {
                GlobalMono.Instance.StopCoroutine(m_CurCoroutine);
                m_CurCoroutine = null;
            }
            m_HasLoaded = false;
            OnSceneUnload();
        }

        public override int OnUpdate()
        {
            if (!m_HasLoaded)
                return base.OnUpdate();
            OnSceneUpdate();
            return base.OnUpdate();
        }

        private IEnumerator Initialize()
        {
            yield return OnInitialize();
            m_HasLoaded = true;
            OnSceneInitialized();
        }

        protected virtual IEnumerator OnInitialize() {
            yield return null;
        }

        protected abstract void OnSceneInitialized();

        protected abstract void OnSceneUpdate();

        protected abstract void OnSceneUnload();
    }
}
